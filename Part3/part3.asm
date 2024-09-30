;1) Set the correct bit mode and origin
[bits 16]
[org 0x7c00]

;2) Store the kernel address we want to write to in a known constant
	KERNEL_ADDRESS equ 0x1000
	
;3) Move the boot drive number from the BIOS to a known variable for storage
	mov [BOOT_DRIVE], DL

;4) Set up our stack
	mov bp, 0x9000
	mov sp, bp

;5) Call a function called disk_test that will perform our read
	call disk_test
;	jmp $

;6) In disk_test - push registers onto the stack
	disk_test:
	pusha

;7) set up the appropriate registers for the disk read operation
	mov AH, 0x02
	mov AL, 0x01
	mov BX, KERNEL_ADDRESS
	mov CH, 0x00
	mov CL, 0x01
	mov DH, 0x00
	mov DL, [BOOT_DRIVE]

;8) run the interrupt service request
	int 0x13

;9) Query the carry flag.  If it is set, then there was a disk read failure and you should print an error message indicating so
	jc disk_read_failure

;10) Compare the number of read sectors after the interrupt to the number you wished to read.
	cmp byte AL, 0x01

;11) Query the result of the compare. If the numbers were not equal, print an error message indicating so.
	jne disk_comparison_failure
	
;12) Pop registers off the stack and return from the function
	popa
	ret

;13) Call a function called test_success that will see if the read was complete
	call test_success
;	jmp $

;14) Calculate the address where the last byte of your bootloader will be loaded into kernel memory.
	test_success:
	mov AL, 0xAA

;15) Compare the last byte of the bootloader (since you know the magic number you should know what this value is) to what lies in that calculated address.  If they are equal, print a success message. If not equal, print an error message.
	cmp byte AL, [0x11FF]
	je success_message
	jne error_message

	disk_comparison_failure:
	mov BX, DISK_COMPARISON_ERROR
	call print_string
	jmp $

	disk_read_failure:
	mov BX, DISK_READ_ERROR
	call print_string
	jmp $
	
	success_message:
	mov BX, READ_SUCCESS_MESSAGE
	call print_string
	jmp $

	error_message:
	mov BX, READ_ERROR_MESSAGE
	call print_string
	jmp $

	print_string:
  	pusha
	mov AH, 0x0E
	print_string_lp:
	mov AL, [BX]
	cmp AL, 0 ; check to see if the string is over
	je print_string_done ; jump if equal
	int 0x10
	add BX, 1
	jmp print_string_lp
	

	print_string_done:
	popa
	ret

	;data
	BOOT_DRIVE db 0
	DISK_COMPARISON_ERROR db 'Comparison error', 0
	DISK_READ_ERROR db 'Unknown error while reading disk.', 0
	READ_SUCCESS_MESSAGE db 'Disk read success', 0
	READ_ERROR_MESSAGE db 'Last bytes do not match', 0
	times 510 - ($-$$) db 0
	dw 0xAA55

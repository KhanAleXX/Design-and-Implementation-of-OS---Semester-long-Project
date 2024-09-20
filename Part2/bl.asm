[bits 16] ; 1) real mode 16 bit directive

	mov AH, 0x0E; 2) Print the letter X to the screen
	mov AL, 'X' 
	int 0x10 

	jmp $ ; 3) Jump to the current instruction to produce an infinite loop
	times 510 - ($-$$) db 0 ; 4) Pad the remaining bootloader with 0s to produce 510 bytes
	dw 0xAA55 ; 5) Add the magic number to the output
	

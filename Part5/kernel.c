void main(void) {
	char* const VGA_BUFFER = (char*) 0xb8000;

	char* str = "Hello World!";

	for (int i=0; str[i] !='\0'; i++) {

		VGA_BUFFER[i*2] = str[i];
		VGA_BUFFER[i*2 + 1] = 0x04;

	}
//	while (1) {}
}

#include "include/console.h"
#include "console/console.c"

void main(void) {
	char* const VGA_BUFFER = (char*) 0xb8000;

	char* str = "Hello World!";

	print_line(str);
}

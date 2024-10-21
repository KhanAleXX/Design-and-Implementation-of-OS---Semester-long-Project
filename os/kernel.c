#include "include/console.h"

void main(void) {

	char* str = "Hello World!\n";
	char* str2 = "This text has been printed on a new line";
	char* str3 = "Same with this text. This also\thas\t\ttabs";

	clear_terminal();
	print_string(str);
	print_line(str2);
	print_string(str3);

}

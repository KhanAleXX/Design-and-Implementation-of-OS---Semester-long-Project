#include "include/console.h"

void main(void) {

//	char* str = "Hello World!\n";
//	char* str2 = "This text has been printed on a new line";
//	char* str3 = "Same with this text. This also\thas\t\ttabs";
//
//	clear_terminal();
//	print_string(str);
//	print_line(str2);
//	print_string(str3);

	clear_terminal();


	char* str1= " HELLO ";
	char* str2 = " WORLD ";
	char* str3 = " TODAY ";

	print_line(str1);
	set_terminal_font_color(BLUE);
	print_line(str2);
	set_terminal_font_color(YELLOW);
	print_line(str3);
	print_character_with_color('A', GREEN);
	print_string_with_color(" BIG STRING", CYAN);
	print_line_with_color("A new line", BROWN);
	print_line_with_color(" is here", RED);

	print_line(str1);
	set_terminal_font_color(BLUE);
	print_line(str2);
	set_terminal_font_color(YELLOW);
	print_line(str3);
	print_character_with_color('A', GREEN);
	print_string_with_color(" BIG STRING", CYAN);
	print_line_with_color("A new line", BROWN);
	print_line_with_color(" is here", RED);

	print_line(str1);
	set_terminal_font_color(BLUE);
	print_line(str2);
	set_terminal_font_color(YELLOW);
	print_line(str3);
	print_character_with_color('A', GREEN);
	print_string_with_color(" BIG STRING", CYAN);
	print_line_with_color("A new line", BROWN);
	print_line_with_color(" is here", RED);

	print_line(str1);
	set_terminal_font_color(BLUE);
	print_line(str2);
	set_terminal_font_color(YELLOW);
	print_line(str3);
	print_character_with_color('A', GREEN);
	print_string_with_color(" BIG STRING", CYAN);
	print_line_with_color("A new line", BROWN);
	print_line_with_color(" is here", RED);

	print_line(str1);
	set_terminal_font_color(BLUE);
	print_line(str2);
	set_terminal_font_color(YELLOW);
	print_line(str3);
	print_character_with_color('A', GREEN);
	print_string_with_color(" BIG STRING", CYAN);
	print_line_with_color("A new line", BROWN);

	print_line_with_color(" is here", RED);}

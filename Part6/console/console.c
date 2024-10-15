#include "../include/console.h"

static int term_pos = 0;

void print_character(char c)
{
	VGA_BUFFER[term_pos++] = c;
	VGA_BUFFER[term_pos++] = 0x07;
}

void clear_terminal() 
{
	for (int i=0; i < 2000; i++)
	{
		print_character(0x00);
	}

	term_pos = 0;
}

void print_string(char* str)
{
	for (int i=0; str[i] !='\0'; i++)
	{
		print_character(str[i]);
	}
}

void print_line(char* str) 
{
	print_string(str);
	term_pos = term_pos + (160 - term_pos%160);
}

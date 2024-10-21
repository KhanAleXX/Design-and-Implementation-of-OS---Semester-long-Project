#include "../include/console.h"

char* const VGA_BUFFER = (char*) 0xb8000;
const int TAB = 8;
static int term_pos = 0;

void new_line() 
{
	term_pos = term_pos + (160 - term_pos%160);
}

void tab()
{
	term_pos = term_pos + (TAB - term_pos%TAB);
}

void print_character(char c)
{
	VGA_BUFFER[term_pos++] = c;
	VGA_BUFFER[term_pos++] = 0x04;
}

void clear_terminal() 
{
	for (int i=0; i < 2000; i++)
	{
		print_character(0x20);
	}

	term_pos = 0;
}

void print_string(char* str)
{
	for (int i=0; str[i] !='\0'; i++)
	{
		if (str[i] == '\n')
		{
			new_line();
		}
		else if (str[i] == '\t')
		{
			tab();
		}
		else 
		{
			print_character(str[i]);
		}
	}
}

void print_line(char* str) 
{
 	print_string(str);
	new_line();
}

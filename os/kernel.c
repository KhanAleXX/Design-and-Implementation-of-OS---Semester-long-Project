#include "include/console.h"
#include "include/portmap.h"
#include "include/keyboard.h"
#include "include/command.h"

#include <stdint.h>


char input[196];
uint8_t byte;
int i = 0;

void get_input()
{
	i = 0;
	while (1) 
	{
		byte = scan();
		if (byte == 0)
			continue;

		char character = charmap[byte];
		print_character(charmap[byte]);
		if (character == '\n')
		{
			input[i] = '\0';
			parse_and_execute_command(input);

			break;
		}
		else if (i < 195)
		{
			input[i++] = character;
		}

	}
}
void main(void) 
{
	clear_terminal();

	while(1)
	{
		print_string("> ");
		get_input();
	}
}

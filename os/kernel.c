#include "include/console.h"
#include "include/portmap.h"
#include "include/keyboard.h"
#include "include/command.h"

#include <stdint.h>

void main(void) 
{
	clear_terminal();

	while(1)
	{
		print_string("> ");
		get_input();
	}
}

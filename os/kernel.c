#include "include/console.h"
#include "include/portmap.h"
#include "include/keyboard.h"

#include <stdint.h>

void main(void) 
{
	clear_terminal();

	uint8_t byte;

	while(1) {

	     while ( byte = scan()) {

		  print_character(charmap[byte]);

	     }

	}
}

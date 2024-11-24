#include "../include/console.h"
#include "../include/portmap.h"
#include "../include/keyboard.h"

#include <stdint.h>

char* const VGA_BUFFER = (char*) 0xb8000;
const int TAB = 8;
static int term_pos = 0;

static int terminal_font_color = GRAY;
static int terminal_background_color = BLACK;

static void update_cursor()
{
	uint16_t cursor_position = term_pos >> 1;
	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t)(cursor_position));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t)(cursor_position >> 8));
}

void set_terminal_font_color(VGA_Color color)
{
	terminal_font_color = color;
}

void set_terminal_background_color(VGA_Color color)
{
	terminal_background_color = color;
}

void new_line() 
{
	term_pos = term_pos + (160 - term_pos%160);
}

void tab()
{
	term_pos = term_pos + (TAB - term_pos%TAB);
}

void print_character_with_color(char c, VGA_Color color)
{
	if (c == '\n')
	{
		new_line();
		update_cursor();
	}
	else if (c == '\t')
	{
		tab();
		update_cursor();
	}
	else 
	{
		VGA_BUFFER[term_pos++] = c;
		VGA_BUFFER[term_pos++] = (terminal_background_color << 4) | color;
		update_cursor();
	}
}

void clear_terminal() 
{
	for (int i=0; i < 2000; i++)
	{
		print_character(0x20);
	}

	term_pos = 0;
}

void print_string_with_color(char* str, VGA_Color color)
{
	for (int i=0; str[i] !='\0'; i++)
	{
		print_character_with_color(str[i], color);
	}
}

void print_line_with_color(char* str, VGA_Color color) 
{
 	print_string_with_color(str, color);
	new_line();
}

void print_character(char c)
{
	print_character_with_color(c, terminal_font_color);
}

void print_string(char* str)
{
	print_string_with_color(str, terminal_font_color);
}

void print_line(char* str)
{
	print_line_with_color(str, terminal_font_color);
}

void print_prompt() 
{
	set_terminal_font_color(GRAY);
	set_terminal_background_color(BLACK);
	print_string("~> ");
}

// Display help message
void display_help() {
	print_line("Commands:\n");
	print_line("  exit - Exit terminal.\n");
	print_line("  help - List commands.\n");
	print_line("  set-terminal-font-color -COLOR - Change font color.\n");
	print_line("  set-terminal-background-color -COLOR - Change background color.\n");
}


#include "../include/command.h"
#include "../include/console.h"
#include "../include/exit.h"
#include "../include/string.h"
#include "../include/keyboard.h"

#include <stdint.h>

#define MAX_COMMAND_LENGTH 64
#define MAX_PARAM_LENGTH 128

char commandBuffer[MAX_COMMAND_LENGTH];
char paramBuffer[MAX_PARAM_LENGTH];

char input[196];
uint8_t byte;
int x = 0;

void get_input()
{
	x = 0;
	while (1) 
	{
		byte = scan();
		if (byte == 0)
			continue;

		char character = charmap[byte];
		print_character(charmap[byte]);

		if (character == '\n')
		{
			input[x] = '\0';
			parse_and_execute_command(input);

			break;
		}
		else if (x < 195)
		{
			input[x++] = character;
		}

	}
}

void parse_command(char* input) {
    int i = 0;
    int j = 0;
    while (input[i] && input[i] != ' ' && i < MAX_COMMAND_LENGTH - 1) {
        commandBuffer[i] = input[i];
        i++;
    }
    commandBuffer[i] = '\0';

    if (input[i] == ' ') {  
        i++;
        while (input[i] && j < MAX_PARAM_LENGTH - 1) {
            paramBuffer[j++] = input[i++];
        }
    }
    paramBuffer[j] = '\0';
}

void execute_command() {
    if (strcmp(commandBuffer, "exit") == 0) {
        exit_terminal();
    } else if (strcmp(commandBuffer, "help") == 0) {
        display_help();
    } else if (strcmp(commandBuffer, "set-terminal-font-color") == 0) {
        if (paramBuffer[0] == '-') {
            if (strcmp(paramBuffer, "-black") == 0) {
                set_terminal_font_color(BLACK);
            } else if (strcmp(paramBuffer, "-blue") == 0) {
                set_terminal_font_color(BLUE);
            } else if (strcmp(paramBuffer, "-green") == 0) {
                set_terminal_font_color(GREEN);
            } else if (strcmp(paramBuffer, "-cyan") == 0) {
                set_terminal_font_color(CYAN);
            } else if (strcmp(paramBuffer, "-red") == 0) {
                set_terminal_font_color(RED);
            } else if (strcmp(paramBuffer, "-brown") == 0) {
                set_terminal_font_color(BROWN);
            } else if (strcmp(paramBuffer, "-gray") == 0) {
                set_terminal_font_color(GRAY);
            } else if (strcmp(paramBuffer, "-white") == 0) {
                set_terminal_font_color(WHITE);
            } else {
                print_line("Error: Unknown font color. Use -COLOR\n");
            }
        } else {
            print_line("Error: Invalid parameter format. Use -COLOR\n");
        }
    } else if (strcmp(commandBuffer, "set-terminal-background-color") == 0) {
        if (paramBuffer[0] == '-') {
            if (strcmp(paramBuffer, "-black") == 0) {
                set_terminal_background_color(BLACK);
            } else if (strcmp(paramBuffer, "-blue") == 0) {
                set_terminal_background_color(BLUE);
            } else if (strcmp(paramBuffer, "-green") == 0) {
                set_terminal_background_color(GREEN);
            } else if (strcmp(paramBuffer, "-cyan") == 0) {
                set_terminal_background_color(CYAN);
            } else if (strcmp(paramBuffer, "-red") == 0) {
                set_terminal_background_color(RED);
            } else if (strcmp(paramBuffer, "-brown") == 0) {
                set_terminal_background_color(BROWN);
            } else if (strcmp(paramBuffer, "-gray") == 0) {
                set_terminal_background_color(GRAY);
            } else if (strcmp(paramBuffer, "-white") == 0) {
                set_terminal_background_color(WHITE);
            } else {
                print_line("Error: Unknown background color. Use -COLOR\n");
            }
        } else {
            print_line("Error: Invalid parameter format. Use -COLOR\n");
        }
    } else {
        print_line("Error: Unknown command. Type 'help' for commands.\n");
    }
}

void parse_and_execute_command(char* input) {
    parse_command(input);
    execute_command();
}

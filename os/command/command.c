#include "../include/command.h"
#include "../include/console.h"
#include "../include/exit.h"
#include "../include/string.h"

#define MAX_COMMAND_LENGTH 64
#define MAX_PARAM_LENGTH 128

char commandBuffer[MAX_COMMAND_LENGTH];
char paramBuffer[MAX_PARAM_LENGTH];

// Parse the command into commandBuffer and paramBuffer
void parse_command(char* input) {
    int i = 0, j = 0;
    while (input[i] && input[i] != ' ' && i < MAX_COMMAND_LENGTH - 1) {
        commandBuffer[i] = input[i];
        i++;
    }
    commandBuffer[i] = '\0';

    if (input[i] == ' ') {  // Found a space, start reading params
        i++;
        while (input[i] && j < MAX_PARAM_LENGTH - 1) {
            paramBuffer[j++] = input[i++];
        }
    }
    paramBuffer[j] = '\0';
}

// Execute command based on parsed input
void execute_command() {
    if (strcmp(commandBuffer, "exit") == 0) {
        exit_terminal();
    } else if (strcmp(commandBuffer, "help") == 0) {
        display_help();
    } else if (strcmp(commandBuffer, "set-terminal-font-color") == 0) {
        if (paramBuffer[0] == '-') {
//            if (!strcmp(paramBuffer[1], "blue"))
                set_terminal_font_color(BLUE);
        } else {
            print_line("Error: Invalid parameter format.\n");
        }
    } else if (strcmp(commandBuffer, "set-terminal-background-color") == 0) {
        if (paramBuffer[0] == '-') {
//	    if (!strcmp(++paramBuffer, "white"))
	        set_terminal_background_color(RED);
        } else {
            print_line("Error: Invalid parameter format.\n");
        }
    } else {
        print_line("Error: Unknown command. Type 'help' for commands.\n");
    }
}

// Parse and execute a command
void parse_and_execute_command(char* input) {
    parse_command(input);
    execute_command();
}

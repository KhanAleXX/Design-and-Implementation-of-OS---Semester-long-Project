#ifndef OS_INCLUDE_CONSOLE_H
#define OS_INCLUDE_CONSOLE_H

typedef enum {
        BLACK = 0,
        BLUE,
        GREEN,
        CYAN,
        RED,
        PURPLE,
        BROWN,
        GRAY,
        DARK_GRAY,
        LIGHT_BLUE,
        LIGHT_GREEN,
        LIGHT_CYAN,
        LIGHT_RED,
        LIGHT_PURPLE,
        YELLOW,
        WHITE
} VGA_Color;

void set_terminal_font_color(VGA_Color);
void set_terminal_background_color(VGA_Color);
void print_character_with_color(char c, VGA_Color);
void print_string_with_color(char* str, VGA_Color);
void print_line_with_color(char*, VGA_Color);

void new_line();
void tab();
void clear_terminal();
void print_character(char c);
void print_string(char* str);
void print_line(char* str);

#endif

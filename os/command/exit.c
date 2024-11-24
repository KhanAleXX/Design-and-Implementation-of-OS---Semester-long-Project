#include "../include/console.h"
#include "../include/exit.h"

void exit_terminal() {
    print_line("Exiting terminal...");
    __asm__("hlt");  // Halts CPU
}

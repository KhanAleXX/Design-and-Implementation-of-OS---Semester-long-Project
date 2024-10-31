#ifndef OS_INCLUDE_CONSOLE_H
#define OS_INCLUDE_CONSOLE_H

#include <stdint.h>

uint8_t inb(uint16_t port);
void outb(uint16_t port, uint8_t val);

#endif

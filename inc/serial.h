#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <io_port.h>
#include <utils.h>
#include <memory.h>
#include <stddef.h>


void init_serial_port(void);

void serial_putchar(char c);

void serial_write(const char *buf, size_t size);

#endif /* __SERIAL_H__ */
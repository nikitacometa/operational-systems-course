#ifndef __SERIAL_INIT_H__
#define __SERIAL_INIT_H__

#include <io_port.h>
#include <utils.h>


static const int serial_addr = 0x3f8;


void init_serial_port();

void print_to_serial_port(char *s);

#endif /* __SERIAL_INIT_H__ */
#include <desc.h>
#include <ints.h>
#include <ioport.h>
#include <serial.h>

void main(void) {
	init_serial_port();

	print_to_serial_port("Hello, world!\n");
	print_to_serial_port("And bye!\n");
}

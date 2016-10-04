#include <serial_init.h>


void disable_interrupts() {
	clear_bit(SERIAL_PORT + 3, 7);

	out8(SERIAL_PORT + 1, 0);
}

void set_div(int div) {
	set_bit(SERIAL_PORT + 3, 7);

	out8(SERIAL_PORT, low(div));
	out8(SERIAL_PORT + 1, high(div));
}

void set_format() {
	set_bit(SERIAL_PORT + 3, 0);
	set_bit(SERIAL_PORT + 3, 1);

	clear_bit(SERIAL_PORT + 3, 2);
	clear_bit(SERIAL_PORT + 3, 3);
	clear_bit(SERIAL_PORT + 3, 7);
}

void init_serial_port() {
	disable_interrupts();
	set_div(1);
	set_format();
}
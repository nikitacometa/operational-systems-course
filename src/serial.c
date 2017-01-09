#include <serial.h>


void init_serial_port(void) {
	clear_bit(SERIAL_PORT + 3, 7);
	out8(SERIAL_PORT + 1, 0);

	int div = 1;
	set_bit(SERIAL_PORT + 3, 7);
	out8(SERIAL_PORT, low(div));
	out8(SERIAL_PORT + 1, high(div));

	set_bit(SERIAL_PORT + 3, 0);
	set_bit(SERIAL_PORT + 3, 1);
	clear_bit(SERIAL_PORT + 3, 2);
	clear_bit(SERIAL_PORT + 3, 3);
	clear_bit(SERIAL_PORT + 3, 7);
}

void serial_putchar(char c) {
	while (!get_bit(SERIAL_PORT + 5, 5));
	out8(SERIAL_PORT, c);
}

void serial_write(const char *buf, size_t size) {
	for (size_t i = 0; i < size; i++) {
		serial_putchar(buf[i]);
	}
}
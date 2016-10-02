#include <desc.h>
#include <ints.h>
#include <ioport.h>


static uint8_t low(int number) {
	return number & 0xff;
}

static uint8_t high(int number) {
	return (number >> 8) & 0xff;
}


static void set_bit(unsigned short port, int bit) {
	uint8_t tmp = in8(port);
	tmp |= (1 << bit);
	out8(port, tmp);
}

static void clear_bit(unsigned short port, int bit) {
	uint8_t tmp = in8(port);
	tmp &= ~(1 << bit);
	out8(port, tmp);
}

static int get_bit(unsigned short port, int bit) {
	uint8_t tmp = in8(port);
	return (tmp >> bit) & 1;
}


static const int serial_addr = 0x3f8;


static void disable_interrupts() {
	clear_bit(serial_addr + 3, 7);

	out8(serial_addr + 1, 0);
}

static void set_div(int div) {
	set_bit(serial_addr + 3, 7);

	out8(serial_addr, low(div));
	out8(serial_addr + 1, high(div));
}

static void set_format() {
	set_bit(serial_addr + 3, 0);
	set_bit(serial_addr + 3, 1);

	clear_bit(serial_addr + 3, 2);
	clear_bit(serial_addr + 3, 3);
	clear_bit(serial_addr + 3, 7);
}

static void init_serial_port() {
	disable_interrupts();
	set_div(1);
	set_format();
}

static void print_to_serial_port(char *s) {
	while (*s) {
		while (!get_bit(serial_addr + 5, 5));
		out8(serial_addr, *(s++));
	}
}

void main(void) {
	init_serial_port();

	print_to_serial_port("Hello, world!\n");
	print_to_serial_port("And bye!\n");
}

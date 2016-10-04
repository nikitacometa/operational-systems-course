#include <io.h>

void print_char(char c) {
	while (!get_bit(SERIAL_PORT + 5, 5));
	out8(SERIAL_PORT, c);
}

void print_string(char *s) {
	while (*s) {
		print_char(*(s++));
	}
}

void print_uint(int num) {
	if (num > 0) {
		print_uint(num / 10);
		print_char((char) ('0' + (num % 10)));
	}
}

void print_int(int num) {
	if (num == 0) {
		print_char('0');
		return;
	}
	if (num < 0) {
		print_char('-');
		num *= -1;
	}
	print_uint(num);
}
#include <io.h>

void print(char *s) {
	while (*s) {
		while (!get_bit(SERIAL_PORT + 5, 5));
		out8(SERIAL_PORT, *(s++));
	}
}
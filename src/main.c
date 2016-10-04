#include <serial_init.h>
#include <pic_init.h>


void main(void) {
	init_serial_port();

	init_pic();

	__asm__ volatile("int $42");
}

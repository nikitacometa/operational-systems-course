#include <serial_init.h>
#include <pic_init.h>
#include <idt_init.h>
#include <io.h>
#include <ints.h>
#include <pit.h>


void main(void) {
	init_serial_port();

	init_idt();

	init_pic();

	start_timer();

	while(1);
}

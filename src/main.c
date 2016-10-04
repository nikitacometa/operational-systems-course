#include <serial.h>
#include <pic.h>
#include <idt.h>
#include <io.h>
#include <ints.h>
#include <pit.h>


void main(void) {
	init_serial_port();

	init_idt();

	init_pic();

	start_timer();

	set_master_mask(0xFF ^ BIT(0));

	while(1);
}

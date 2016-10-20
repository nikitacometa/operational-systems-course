#include <serial.h>
#include <pic.h>
#include <idt.h>
#include <io.h>
#include <ints.h>
#include <pit.h>
#include <memory_map.h>
#include <utils.h>


void main(void) {
	init_serial_port();

	init_idt();

	init_pic();

	get_memory_map();

	print_memory_map();

	just_hang();
}

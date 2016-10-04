#include <serial_init.h>
#include <pic_init.h>
#include <idt_init.h>
#include <io.h>
#include <ints.h>


void main(void) {
	print_string("Hi!\n");

	init_serial_port();

	print_string("Serial port has been initialized!\n");

	init_idt();

	print_string("IDT has been initialized!\n");

	init_pic();

	print_string("PIC has been initialized!\n");

	__asm__ volatile("int $35");

	print_string("Bye!\n");
}

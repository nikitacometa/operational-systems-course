#include <serial.h>
#include <pic.h>
#include <idt.h>
#include <io.h>
#include <ints.h>
#include <pit.h>
#include <memory_map.h>
#include <utils.h>
#include <buddy_allocator.h>


void main(void) {
	init_serial_port();

	init_idt();

	init_pic();

	init_buddy_allocator();

	printf("Free memory: %d bytes\n", get_free_memory());

	int* a = (int*) alloc_page(2);
	size_t n = PAGE_SIZE * (1 << 2) / sizeof(int);

	printf("Allocated memory for %d ints\n", n);

	printf("Free memory: %d bytes\n", get_free_memory());

	for (size_t i = 0; i < n; i++) {
		a[i] = i;
	}

	int sum = 0;

	for (size_t i = 0; i < n; i++) {
		sum += a[i];
	}

	printf("Their sum is %d\n", sum);

	free_page(a);

	printf("Freed allocated memory\n");

	printf("Free memory: %d bytes\n", get_free_memory());
	
	just_hang();
}

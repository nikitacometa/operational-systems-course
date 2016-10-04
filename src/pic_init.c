#include <pic_init.h>


#define HANDLING           \
    __asm__("pushq %rax"); \
    __asm__("pushq %rbx"); \
    __asm__("pushq %rcx"); \
    __asm__("pushq %rdx"); \
    __asm__("pushq %rsi"); \
    __asm__("pushq %rdi"); \
    __asm__("pushq %rbp"); \
    __asm__("pushq %rsp"); \
    __asm__("pushq %r8");  \
    __asm__("pushq %r9");  \
    __asm__("pushq %r10"); \
    __asm__("pushq %r11"); \
    __asm__("pushq %r12"); \
    __asm__("pushq %r13"); \
    __asm__("pushq %r14"); \
    __asm__("pushq %r15"); \
    __asm__("call handle");\
    __asm__("popq %r15");  \
    __asm__("popq %r14");  \
    __asm__("popq %r13");  \
    __asm__("popq %r12");  \
    __asm__("popq %r11");  \
    __asm__("popq %r10");  \
    __asm__("popq %r9");   \
    __asm__("popq %r8");   \
    __asm__("popq %rsp");  \
    __asm__("popq %rbp");  \
    __asm__("popq %rdi");  \
    __asm__("popq %rsi");  \
    __asm__("popq %rdx");  \
    __asm__("popq %rcx");  \
    __asm__("popq %rbx");  \
    __asm__("popq %rax");  \
    __asm__("iretq");  


void handle() {
    print_to_serial_port("An interrupt has been handled!\n");
}

void handler_with_error() {
    __asm__("add $8, %rsp");
    HANDLING
}

void handler() {
    HANDLING
}


#define ENTRIES_NUMBER 256
#define SYSTEM_INTERRUPTS 32

static struct desc_table_entry_ptr entries[ENTRIES_NUMBER];

void init_entry(int i) {
	uint64_t offset;
	if (i == 8 || (10 <= i && i <= 14) || i == 17) {
		offset = (uint64_t) &handler_with_error;
	} else {
		offset = (uint64_t) &handler;
	}
	entries[i].offset_0_15 = (uint16_t) (offset & 0xFFFF);
	entries[i].segm_sel = KERNEL_CS;
	entries[i].params = BIT(15); // P
	if (i < SYSTEM_INTERRUPTS) {
		entries[i].params |= (3 << 13); // DPL
	}
	entries[i].params |= (14 << 8); // TYPE
	entries[i].offset_16_31 = (uint16_t) ((offset >> 16) & 0xFFFF);
	entries[i].offset_32_63 = (uint32_t) ((offset >> 32) & 0xFFFFFFFF);
	entries[i].reserved = 0;
}

void init_idt() {
	for (int i = 0; i < ENTRIES_NUMBER; i++) {
		init_entry(i);
	}
}

void init_pic() {
	init_idt();

	struct desc_table_ptr table;
    table.size = sizeof(entries) - 1;
    table.addr = (uint64_t) &entries;
    write_idtr(&table);
}
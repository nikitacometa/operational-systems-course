#include <pic_init.h>


extern uint64_t handlers[]; 


void handle() {
    print("An interrupt has been handled!\n");
}



#define ENTRIES_NUMBER 256
#define SYSTEM_INTERRUPTS 32

static struct desc_table_entry_ptr entries[ENTRIES_NUMBER];

void init_entry(int i) {
	uint64_t offset = handlers[i];
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

    struct desc_table_ptr table;
    table.size = sizeof(entries) - 1;
    table.addr = (uint64_t) &entries;
    write_idtr(&table);
}

void init_pic() {


}
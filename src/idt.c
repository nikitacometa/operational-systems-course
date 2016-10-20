#include <idt.h>


extern uint64_t handlers[]; 


void slave_handle(uint64_t handler_id) {
    printf("Interrupt #%u has been handled by slave!\n", handler_id);

    out8(SLAVE_COMMAND_PORT, BIT(5));
    out8(MASTER_COMMAND_PORT, BIT(5));
}

void master_handle(uint64_t handler_id) {
    printf("Interrupt #%u has been handled by master!\n", handler_id);

    out8(MASTER_COMMAND_PORT, BIT(5));
}

void handle(uint64_t handler_id) {
    if (handler_id < SYSTEM_INTERRUPTS) {
        printf("System interrupt #%u has been handled somehow!\n", handler_id);
    }
    if (MASTER_FIRST_HANDLER <= handler_id && handler_id <= MASTER_LAST_HANDLER) {
        master_handle(handler_id);
    }
    if (SLAVE_FIRST_HANDLER <= handler_id && handler_id <= SLAVE_LAST_HANDLER) {
        slave_handle(handler_id);
    }
}


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
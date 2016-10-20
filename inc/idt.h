#ifndef __IDT_H__
#define __IDT_H__

#include <stdint.h>
#include <memory.h>
#include <io.h>
#include <pic.h>


struct desc_table_ptr {
	uint16_t size;
	uint64_t addr;
} __attribute__((packed));


static inline void read_idtr(struct desc_table_ptr *ptr) {
	__asm__ ("sidt %0" : "=m"(*ptr));
}

static inline void write_idtr(const struct desc_table_ptr *ptr) {
	__asm__ ("lidt %0" : : "m"(*ptr));
}

static inline void read_gdtr(struct desc_table_ptr *ptr) {
	__asm__ ("sgdt %0" : "=m"(*ptr));
}

static inline void write_gdtr(const struct desc_table_ptr *ptr) {
	__asm__ ("lgdt %0" : : "m"(*ptr));
}


struct desc_table_entry_ptr {
	uint16_t offset_0_15;
	uint16_t segm_sel;
	uint16_t params;
	uint16_t offset_16_31;
	uint32_t offset_32_63;
	uint32_t reserved;
} __attribute__((packed));


#define ENTRIES_NUMBER    48
#define SYSTEM_INTERRUPTS 32


void init_idt(void);

#endif /* __IDT_H__ */
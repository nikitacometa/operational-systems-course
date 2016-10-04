#ifndef __PIC_INIT_H__
#define __PIC_INIT_H__

#include <desc.h>
#include <serial_init.h>
#include <memory.h>


struct desc_table_entry_ptr {
	uint16_t offset_0_15;
	uint16_t segm_sel;
	uint16_t params;
	uint16_t offset_16_31;
	uint32_t offset_32_63;
	uint32_t reserved;
} __attribute__((packed));


void init_pic();

#endif /* __PIC_INIT_H__ */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#define VIRTUAL_BASE	0xffffffff80000000
#define PAGE_SIZE	0x1000
#define KERNEL_CS	0x08
#define KERNEL_DS	0x10

#define SERIAL_PORT         0x3f8
#define MASTER_COMMAND_PORT 0x20
#define MASTER_DATA_PORT    0x21
#define SLAVE_COMMAND_PORT  0xA0
#define SLAVE_DATA_PORT     0xA1

#endif /*__MEMORY_H__*/

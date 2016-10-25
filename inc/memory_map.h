#ifndef __MEMORY_MAP_H__
#define __MEMORY_MAP_H__

#include <stdint.h>
#include <stddef.h>
#include <io.h>
#include <utils.h>

//3.3 https://www.gnu.org/software/grub/manual/multiboot/multiboot.html

struct memory_map_entry {
	uint32_t size;
	uint64_t base_addr;
	uint64_t length;
	uint32_t type;
} __attribute__((packed));

typedef struct memory_map_entry memory_map_entry_t;

memory_map_entry_t new_entry(uint32_t size, uint64_t base_addr, uint64_t end_addr, uint32_t type);


void get_memory_map(void);

void print_memory_map(void);

memory_map_entry_t* get_max_available_region(void);


#define MEMORY_MAP_MAX_SIZE 128

#define TYPE_KERNEL      0
#define TYPE_AVAILABLE   1
#define TYPE_UNAVAILABLE 2

#define ENTRY_SIZE 20

#endif /* __MEMORY_MAP_H__ */
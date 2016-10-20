#ifndef __MEMORY_MAP_H__
#define __MEMORY_MAP_H__

#include <stdint.h>


struct memory_map_entry {
	uint32_t size;
	uint64_t base_addr;
	uint64_t length;
	uint64_t type;
};

void get_memory_map(void);

void print_memory_map(void);

#endif /* __MEMORY_MAP_H__ */
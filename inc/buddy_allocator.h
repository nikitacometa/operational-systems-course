#ifndef __BUDDY_ALLOCATOR_H__
#define __BUDDY_ALLOCATOR_H__

#include <memory_map.h>
#include <memory.h>


#define STATUS_FREE 0
#define STATUS_BUSY 1

typedef struct block_descriptor block_descriptor_t;

struct block_descriptor {
	uint8_t status;
	uint8_t order;
	block_descriptor_t* next;
	block_descriptor_t* prev;
};


#define MAX_ORDER 20 // 4gb

void init_buddy_allocator(void);

void* alloc_page(uint8_t order); // returns memory region of size PAGE_SIZE * 2^order

void free_page(void* addr);

uint64_t get_free_memory(void);


block_descriptor_t NOTHING_OBJECT;
#define NOTHING (&NOTHING_OBJECT)

#define ID_NO_FREE_BLOCKS 0xffffffff


static inline void* get_virt_addr(uint64_t phys_addr) {
	return (void *) (phys_addr + VIRTUAL_BASE);
}

static inline uint64_t get_phys_addr(void* virt_addr) {
	return (uint64_t) virt_addr - VIRTUAL_BASE;
}

#endif /* __BUDDY_ALLOCATOR_H__ */
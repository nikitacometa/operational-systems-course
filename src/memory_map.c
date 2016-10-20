#include <memory_map.h>

extern uint64_t multiboot_info;

#define MEMORY_MAP_MAX_SIZE 128

size_t memory_map_size = 0;
memory_map_entry_t memory_map[MEMORY_MAP_MAX_SIZE];

void get_memory_map(void) {
	uint32_t flags = *(uint32_t *) multiboot_info;
	if (!(flags & BIT(6))) {
        printf("Can't get memory map because of bad multiboot information structure :(\n");
        just_hang();
    }

    uint32_t mmap_length = *(uint32_t *) (multiboot_info + 44);
    uint32_t mmap_addr = *(uint32_t *) (multiboot_info + 48);

    uint32_t pos = 0;
    while (pos < mmap_length) {
    	memory_map[memory_map_size].size = *(uint32_t *) (uint64_t) (mmap_addr + pos);
        memory_map[memory_map_size].base_addr = *(uint64_t *) (uint64_t) (mmap_addr + pos + 4);
        memory_map[memory_map_size].length = *(uint64_t *) (uint64_t) (mmap_addr + pos + 12);
        memory_map[memory_map_size].type = *(uint32_t *) (uint64_t) (mmap_addr + pos + 20);
        pos += memory_map[memory_map_size].size + 4;
        memory_map_size++;
    }
}

void print_memory_map(void) {
	for (size_t i = 0; i < memory_map_size; i++) {
		char *availability = memory_map[i].type == 1 ? "available" : "unavailable";
		printf("Memory region %p-%p is %s!\n", memory_map[i].base_addr, memory_map[i].base_addr + memory_map[i].length - 1, availability);
	}
}
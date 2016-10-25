#include <memory_map.h>

extern uint64_t multiboot_info;
extern uint32_t multiboot_header[];

uint8_t got_memory_map = 0;

size_t memory_map_size = 0;
memory_map_entry_t memory_map[MEMORY_MAP_MAX_SIZE];
memory_map_entry_t kernel;
uint64_t kernel_end_addr;

memory_map_entry_t new_entry(uint32_t size, uint64_t base_addr, uint64_t end_addr, uint32_t type) {
	memory_map_entry_t result;
	result.size = size;
	result.base_addr = base_addr;
	result.length = end_addr - base_addr + 1;
	result.type = type;
	return result;
}

void add_entry(memory_map_entry_t entry) {
	memory_map[memory_map_size++] = entry;
}

void init_kernel_entry(void) {
	kernel = new_entry(ENTRY_SIZE, multiboot_header[4], multiboot_header[6], TYPE_KERNEL);
	kernel_end_addr = multiboot_header[6];
	add_entry(kernel);
}

void add_entry_kernel_intersection_check(memory_map_entry_t entry) {
	uint64_t entry_end_addr = entry.base_addr + entry.length - 1;
	if (kernel_end_addr < entry.base_addr || entry_end_addr < kernel.base_addr) {
		add_entry(entry);
	} else if (kernel.base_addr <= entry.base_addr && entry_end_addr <= kernel_end_addr) {
	} else if (entry.base_addr < kernel.base_addr && kernel_end_addr < entry_end_addr) {
		add_entry(new_entry(ENTRY_SIZE, entry.base_addr, kernel.base_addr - 1, entry.type));
		add_entry(new_entry(ENTRY_SIZE, kernel_end_addr + 1, entry_end_addr, entry.type));
	} else if (kernel.base_addr < entry.base_addr) {
		add_entry(new_entry(ENTRY_SIZE, kernel_end_addr + 1, entry_end_addr, entry.type));
	} else {
		add_entry(new_entry(ENTRY_SIZE, entry.base_addr, kernel.base_addr - 1, entry.type));	
	}
}

void sort_entries(void) {
	for (size_t i = 0; i < memory_map_size - 1; i++) {
		for (size_t j = 0; j < memory_map_size - i - 1; j++) {
			if (memory_map[j].base_addr > memory_map[j + 1].base_addr) {
				memory_map_entry_t tmp = memory_map[j];
				memory_map[j] = memory_map[j + 1];
				memory_map[j + 1] = tmp;
			}
		}
	}
}

void get_memory_map(void) {
	if (got_memory_map) {
		return;
	}
	uint32_t flags = *(uint32_t *) multiboot_info;
	if (!(flags & BIT(6))) {
        printf("No memory map provided.\n");
        just_hang();
    }

    init_kernel_entry();

    uint32_t mmap_length = *(uint32_t *) (multiboot_info + 44);
    uint32_t mmap_addr = *(uint32_t *) (multiboot_info + 48);

    uint32_t pos = 0;
    while (pos < mmap_length) {
    	memory_map_entry_t entry;
    	entry.size = *(uint32_t *) (uint64_t) (mmap_addr + pos);
        entry.base_addr = *(uint64_t *) (uint64_t) (mmap_addr + pos + 4);
        entry.length = *(uint64_t *) (uint64_t) (mmap_addr + pos + 12);
        entry.type = *(uint32_t *) (uint64_t) (mmap_addr + pos + 20);
        add_entry_kernel_intersection_check(entry);
        pos += entry.size + 4;
    }

    sort_entries();

    got_memory_map = 1;
}

char* region_status(memory_map_entry_t entry) {
	switch (entry.type) {
		case TYPE_KERNEL:
			return "kernel";
		case TYPE_AVAILABLE:
			return "available";
		default:
			return "reserved";
	}
} 

void print_memory_map(void) {
	printf("Memory map:\n");
	for (size_t i = 0; i < memory_map_size; i++) {
		printf("[%p; %p] %s\n", memory_map[i].base_addr, memory_map[i].base_addr + memory_map[i].length - 1, region_status(memory_map[i]));
	}
}

memory_map_entry_t* get_max_available_region(void) {
	memory_map_entry_t* res = NULL;
	for (size_t i = 0; i < memory_map_size; i++) {
		if (memory_map[i].type == TYPE_AVAILABLE && (res == NULL || res->length < memory_map[i].length)) {
			res = &memory_map[i];
		}
	}
	return res;
}
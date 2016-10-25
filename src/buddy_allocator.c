#include <buddy_allocator.h>

block_descriptor_t* lists[MAX_ORDER];
block_descriptor_t* descriptors;

uint64_t free_pages_count;

uint64_t first_page_addr;
uint32_t total_pages;


uint32_t get_id(block_descriptor_t* desc) {
	return (desc - descriptors) / sizeof(block_descriptor_t);
}

uint32_t get_buddy_id(uint32_t id, uint8_t order) {
	return id ^ (1 << order);
}

uint64_t get_addr(uint32_t id) {
	return first_page_addr + id * PAGE_SIZE;
}

uint8_t is_free(uint32_t id) {
	return descriptors[id].status == STATUS_FREE;
}

void add_to_list(uint32_t id) {
	uint8_t order = descriptors[id].order;
	descriptors[id].prev = lists[order];
	lists[order]->next = &descriptors[id];
	lists[order] = &descriptors[id];
}

void remove_from_list(uint32_t id) {
	descriptors[id].next->prev = descriptors[id].prev;
	descriptors[id].prev->next = descriptors[id].next;
	descriptors[id].next = NOTHING;
	descriptors[id].prev = NOTHING;
}

void free_block(uint32_t id) {
	if (is_free(id)) {
		return;
	}
	descriptors[id].status = STATUS_FREE;
	while (1) {
		uint32_t buddy_id = get_buddy_id(id, descriptors[id].order);
		if (buddy_id < total_pages && is_free(buddy_id) && descriptors[buddy_id].order == descriptors[id].order) {
			remove_from_list(buddy_id);
			if (id > buddy_id) {
				uint32_t tmp = id;
				id = buddy_id;
				buddy_id = tmp;
			}
			descriptors[buddy_id].status = STATUS_BUSY;
			descriptors[id].order++;
		} else {
			add_to_list(id);
			break;
		}
	}
}

uint32_t get_block(uint8_t order) {
	uint8_t cur = order;
	while (cur < MAX_ORDER && lists[cur] == NOTHING) {
		cur++;
	}
	if (cur >= MAX_ORDER) {
		return ID_NO_FREE_BLOCKS;
	}
	uint32_t id = get_id(lists[cur]);
	remove_from_list(id);
	while (descriptors[id].order > order) {
		descriptors[id].order--;
		free_block(get_buddy_id(id, descriptors[id].order));
	}
	return id;
}

void init_page(uint32_t id) {
	descriptors[id].status = STATUS_BUSY;
	descriptors[id].order = 0;
	descriptors[id].next = NOTHING;
	descriptors[id].prev = NOTHING;
}

void init_buddy_allocator(void) {
	get_memory_map();

	memory_map_entry_t* allocator_area = get_max_available_region();

	total_pages = (allocator_area->length - PAGE_SIZE + 1) / (PAGE_SIZE + sizeof(block_descriptor_t));

	if (total_pages < 1) {
		hang("Failed to init buddy allocator: no memory.");
	}

	descriptors = (block_descriptor_t*) get_virt_addr(allocator_area->base_addr);

	uint64_t start_addr = allocator_area->base_addr + total_pages * sizeof(block_descriptor_t);
	first_page_addr = (start_addr + PAGE_SIZE - 1) / PAGE_SIZE * PAGE_SIZE;

	for (size_t i = 0; i < MAX_ORDER; i++) {
		lists[i] = NOTHING;
	}

	for (size_t id = 0; id < total_pages; id++) {
		init_page(id);
	}

	for (size_t id = 0; id < total_pages; id++) {
		free_block(id);
	}

	free_pages_count = total_pages;

	allocator_area->type = TYPE_UNAVAILABLE;
}

void* alloc_page(uint8_t order) {
	uint32_t res_id = get_block(order);
	if (res_id == ID_NO_FREE_BLOCKS) {
		hang("No memory for allocating page.");
	}
	free_pages_count -= (1 << order);
	printf("Got page #%d\n", res_id);
	return get_virt_addr(get_addr(res_id));
}

void free_page(void* addr) {
	uint64_t phys_addr = get_phys_addr(addr);
	if (phys_addr % PAGE_SIZE == 0 && phys_addr >= first_page_addr && phys_addr < first_page_addr + PAGE_SIZE * total_pages) {
		uint32_t id = (phys_addr - first_page_addr) / PAGE_SIZE;
		free_pages_count += (1 << descriptors[id].order);
		printf("Freeing page #%d\n", id);
		free_block(id);
	} else {
		hang("There's no page by specified address.");
	}
}

uint64_t get_free_memory(void) {
	return free_pages_count * PAGE_SIZE;
}

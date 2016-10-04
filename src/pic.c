#include <pic.h>


void init_pic() {
	disable_ints();

    out8(MASTER_COMMAND_PORT, BIT(0) | BIT(4));
    out8(MASTER_DATA_PORT, MASTER_FIRST_HANDLER);
    out8(MASTER_DATA_PORT, BIT(2));
    out8(MASTER_DATA_PORT, BIT(0));
    
    out8(SLAVE_COMMAND_PORT, BIT(0) | BIT(4));
    out8(SLAVE_DATA_PORT, SLAVE_FIRST_HANDLER);
    out8(SLAVE_DATA_PORT, 2);
    out8(SLAVE_DATA_PORT, BIT(0));

    set_master_mask(0xFF ^ BIT(2));
    set_slave_mask(0xFF);

    enable_ints();
}

void set_master_mask(uint8_t mask) {
	out8(MASTER_DATA_PORT, mask);
}

void set_slave_mask(uint8_t mask) {
	out8(SLAVE_DATA_PORT, mask);
}
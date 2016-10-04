#include <pic_init.h>


void init_pic() {
    out8(MASTER_COMMAND_PORT, BIT(0) | BIT(4));
    out8(MASTER_DATA_PORT, MASTER_FIRST_HANDLER);
    out8(MASTER_DATA_PORT, BIT(2));
    out8(MASTER_DATA_PORT, BIT(0));
    
    out8(SLAVE_COMMAND_PORT, BIT(0) | BIT(4));
    out8(SLAVE_DATA_PORT, SLAVE_FIRST_HANDLER);
    out8(SLAVE_DATA_PORT, 2);
    out8(SLAVE_DATA_PORT, BIT(0));

    out8(MASTER_DATA_PORT, 0xFF ^ BIT(2));
    out8(SLAVE_DATA_PORT, 0xFF);
}
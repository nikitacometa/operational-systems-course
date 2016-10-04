#include <pit.h>

void start_timer() {
	out8(TIMER_COMMAND_PORT, (2 << 1) | BIT(4) | BIT(5));
    out8(TIMER_DATA_PORT, 0xFF);
    out8(TIMER_DATA_PORT, 0xFF);
}
#ifndef __UTILS_H__
#define __UTILS_H__

static uint8_t bit(int bit_id) {
	return 1 << bit_id;
}

static uint8_t low(int number) {
	return number & 0xff;
}

static uint8_t high(int number) {
	return (number >> 8) & 0xff;
}


static void set_bit(unsigned short port, int bit_id) {
	uint8_t tmp = in8(port);
	tmp |= bit(bit_id);
	out8(port, tmp);
}

static void clear_bit(unsigned short port, int bit_id) {
	uint8_t tmp = in8(port);
	tmp &= ~bit(bit_id);
	out8(port, tmp);
}

static int get_bit(unsigned short port, int bit_id) {
	uint8_t tmp = in8(port);
	return (tmp >> bit_id) & 1;
}

#endif /* __UTILS_H__ */
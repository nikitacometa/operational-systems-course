#ifndef __UTILS_H__
#define __UTILS_H__

#define BIT(n) (1 << (n))

static inline uint8_t low(int number) {
	return number & 0xff;
}

static inline uint8_t high(int number) {
	return (number >> 8) & 0xff;
}


static inline void set_bit(unsigned short port, int bit) {
	uint8_t tmp = in8(port);
	tmp |= BIT(bit);
	out8(port, tmp);
}

static inline void clear_bit(unsigned short port, int bit) {
	uint8_t tmp = in8(port);
	tmp &= ~BIT(bit);
	out8(port, tmp);
}

static inline int get_bit(unsigned short port, int bit) {
	uint8_t tmp = in8(port);
	return (tmp >> bit) & 1;
}


static inline void qemu_gdb_hang(void) {
#ifdef DEBUG
	static volatile int wait = 1;

	while (wait);
	wait = 1;
#endif
}

static inline void just_hang(void) {
	while (1);
}

#endif /* __UTILS_H__ */
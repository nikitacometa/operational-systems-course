#ifndef __IO_H__
#define __IO_H__

#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <serial.h>


int snprintf(char *buf, size_t size, const char *fmt, ...);

int vsnprintf(char *buf, size_t size, const char *fmt, va_list args);

int printf(const char *fmt, ...);

int vprintf(const char *fmt, va_list args);


static inline void hang(char* mes) {
	printf("%s\n", mes);
	just_hang();
}

#endif /* __IO_H__ */
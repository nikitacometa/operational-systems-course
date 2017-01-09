#ifndef __PIC_H__
#define __PIC_H__

#include <io_port.h>
#include <utils.h>
#include <memory.h>
#include <ints.h>


#define MASTER_FIRST_HANDLER 32
#define MASTER_LAST_HANDLER  39
#define SLAVE_FIRST_HANDLER  40
#define SLAVE_LAST_HANDLER   47


void init_pic(void);

void set_master_mask(uint8_t mask);

void set_slave_mask(uint8_t mask);

#endif /* __PIC_H__ */
#ifndef BH1750FVI_H
#define BH1750FVI_H

#include <stdint.h>

#define BH1750_CHNNL_NO    0
#define BH1750_SLAVE_ADDR  0x46 // 0x23<<1

int bh1750_init(uint8_t chnnlNo, uint8_t slave_address);
uint32_t bh1750_read_lux(uint8_t chnnlNo, uint8_t slave_address);

#endif
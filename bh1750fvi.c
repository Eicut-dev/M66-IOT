#include "bh1750fvi.h"
#include "ql_type.h"
#include "ql_gpio.h"
#include "ql_iic.h"
#include "ql_error.h"

#define CMD_POWER_ON     0x01
#define CMD_RESET        0x07
#define CMD_CONT_HRES    0x10

static void bh1750_write_cmd(uint8_t chnnlNo, uint8_t addr, uint8_t cmd) {
    Ql_IIC_Write(chnnlNo, addr, &cmd, 1);
}

int bh1750_init(uint8_t chnnlNo, uint8_t slave_address) {
    if (Ql_IIC_Config(chnnlNo, TRUE, slave_address, 150) != QL_RET_OK) {
        return -1;
    }

    bh1750_write_cmd(chnnlNo, slave_address, CMD_POWER_ON);
    Ql_Sleep(10);

    bh1750_write_cmd(chnnlNo, slave_address, CMD_RESET);
    Ql_Sleep(10);

    bh1750_write_cmd(chnnlNo, slave_address, CMD_CONT_HRES);
    Ql_Sleep(180); // wait for first measurement

    return 0;
}

uint32_t bh1750_read_lux(uint8_t chnnlNo, uint8_t slave_address) {
    uint8_t buf[2];
    uint16_t raw_lux;

    Ql_IIC_Read(chnnlNo, slave_address, buf, 2);
    raw_lux = (buf[0] << 8) | buf[1];
    return (uint32_t)(raw_lux / 1.2);
}
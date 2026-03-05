/*
 * vl53l0x_platform.c
 *
 * I2C platform layer for VL53L0X API on STM32F411 HAL.
 * Adapts the ST VL53L0X API to HAL_I2C functions using hi2c1.
 */

#include "vl53l0x_platform.h"
#include "main.h"
#include <string.h>

extern I2C_HandleTypeDef hi2c1;

VL53L0X_Error VL53L0X_WriteMulti(VL53L0X_DEV Dev, uint8_t index, uint8_t *pdata, uint32_t count){
    uint8_t buf[count + 1];
    buf[0] = index;
    memcpy(&buf[1], pdata, count);
    HAL_StatusTypeDef st = HAL_I2C_Master_Transmit(&hi2c1, Dev->I2cDevAddr, buf, (uint16_t)(count + 1), VL53L0X_I2C_TIMEOUT);

    return (st == HAL_OK) ? VL53L0X_ERROR_NONE : VL53L0X_ERROR_CONTROL_INTERFACE;
}

VL53L0X_Error VL53L0X_ReadMulti(VL53L0X_DEV Dev, uint8_t index, uint8_t *pdata, uint32_t count){
    HAL_StatusTypeDef st;
    st = HAL_I2C_Master_Transmit(&hi2c1, Dev->I2cDevAddr, &index, 1, VL53L0X_I2C_TIMEOUT);
    if (st != HAL_OK) return VL53L0X_ERROR_CONTROL_INTERFACE;
    st = HAL_I2C_Master_Receive(&hi2c1, Dev->I2cDevAddr, pdata, (uint16_t)count, VL53L0X_I2C_TIMEOUT);
    return (st == HAL_OK) ? VL53L0X_ERROR_NONE: VL53L0X_ERROR_CONTROL_INTERFACE;
}
VL53L0X_Error VL53L0X_WrByte(VL53L0X_DEV Dev, uint8_t index, uint8_t data){
    return VL53L0X_WriteMulti(Dev, index, &data, 1);
}

VL53L0X_Error VL53L0X_WrWord(VL53L0X_DEV Dev, uint8_t index, uint16_t data){
    uint8_t buf[2] = {
        (uint8_t)((data >> 8) & 0xFF),
        (uint8_t)( data       & 0xFF)
    };
    return VL53L0X_WriteMulti(Dev, index, buf, 2);
}

VL53L0X_Error VL53L0X_WrDWord(VL53L0X_DEV Dev, uint8_t index, uint32_t data){
    uint8_t buf[4] = {
        (uint8_t)((data >> 24) & 0xFF),
        (uint8_t)((data >> 16) & 0xFF),
        (uint8_t)((data >>  8) & 0xFF),
        (uint8_t)( data        & 0xFF)
    };
    return VL53L0X_WriteMulti(Dev, index, buf, 4);
}

VL53L0X_Error VL53L0X_RdByte(VL53L0X_DEV Dev, uint8_t index, uint8_t *data){
    return VL53L0X_ReadMulti(Dev, index, data, 1);
}

VL53L0X_Error VL53L0X_RdWord(VL53L0X_DEV Dev, uint8_t index, uint16_t *data){
    uint8_t buf[2] = {0};
    VL53L0X_Error err = VL53L0X_ReadMulti(Dev, index, buf, 2);
    *data = ((uint16_t)buf[0] << 8) | (uint16_t)buf[1];
    return err;
}

VL53L0X_Error VL53L0X_RdDWord(VL53L0X_DEV Dev, uint8_t index, uint32_t *data){
    uint8_t buf[4] = {0};
    VL53L0X_Error err = VL53L0X_ReadMulti(Dev, index, buf, 4);
    *data = ((uint32_t)buf[0] << 24)
          | ((uint32_t)buf[1] << 16)
          | ((uint32_t)buf[2] <<  8)
          |  (uint32_t)buf[3];
    return err;
}
VL53L0X_Error VL53L0X_PollingDelay(VL53L0X_DEV Dev){
    (void)Dev;
    HAL_Delay(5);
    return VL53L0X_ERROR_NONE;
}

VL53L0X_Error VL53L0X_UpdateByte(VL53L0X_DEV Dev, uint8_t index,
                                  uint8_t AndData, uint8_t OrData)
{
    uint8_t data;
    VL53L0X_Error err = VL53L0X_RdByte(Dev, index, &data);
    if (err != VL53L0X_ERROR_NONE) return err;
    data = (data & AndData) | OrData;
    return VL53L0X_WrByte(Dev, index, data);
}

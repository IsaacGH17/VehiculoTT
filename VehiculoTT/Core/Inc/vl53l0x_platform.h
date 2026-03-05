/*
 * vl53l0x_platform.h
 *
 * Platform layer for VL53L0X API on STM32 HAL (I2C1 @ 100kHz)
 */

#ifndef VL53L0X_PLATFORM_H_
#define VL53L0X_PLATFORM_H_

#include "vl53l0x_def.h"
#include "vl53l0x_api.h"

/* Default I2C address of VL53L0X (7-bit = 0x29, shifted left = 0x52) */
#define VL53L0X_DEFAULT_ADDR  0x52U

/* I2C timeout in ms */
#define VL53L0X_I2C_TIMEOUT   100U

/* ---- Functions required by the ST VL53L0X API ---- */

VL53L0X_Error VL53L0X_WriteMulti(VL53L0X_DEV Dev, uint8_t index,
                                  uint8_t *pdata, uint32_t count);

VL53L0X_Error VL53L0X_ReadMulti(VL53L0X_DEV Dev, uint8_t index,
                                 uint8_t *pdata, uint32_t count);

VL53L0X_Error VL53L0X_WrByte(VL53L0X_DEV Dev, uint8_t index,
                              uint8_t data);

VL53L0X_Error VL53L0X_WrWord(VL53L0X_DEV Dev, uint8_t index,
                              uint16_t data);

VL53L0X_Error VL53L0X_WrDWord(VL53L0X_DEV Dev, uint8_t index,
                               uint32_t data);

VL53L0X_Error VL53L0X_RdByte(VL53L0X_DEV Dev, uint8_t index,
                              uint8_t *data);

VL53L0X_Error VL53L0X_RdWord(VL53L0X_DEV Dev, uint8_t index,
                              uint16_t *data);

VL53L0X_Error VL53L0X_RdDWord(VL53L0X_DEV Dev, uint8_t index,
                               uint32_t *data);

VL53L0X_Error VL53L0X_PollingDelay(VL53L0X_DEV Dev);

#endif /* VL53L0X_PLATFORM_H_ */

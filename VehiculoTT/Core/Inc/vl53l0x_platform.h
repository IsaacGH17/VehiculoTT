/*
 * vl53l0x_platform.h
 *
 * Platform layer for VL53L0X API on STM32F411 HAL (I2C1 @ 100kHz)
 *
 * This file MUST define:
 *   - VL53L0X_Dev_t   (hardware device struct)
 *   - VL53L0X_DEV     (pointer typedef used throughout the API)
 *   - Logging macros  (stub them out for embedded targets)
 *   - I2C function prototypes
 */

#ifndef VL53L0X_PLATFORM_H_
#define VL53L0X_PLATFORM_H_

#include <stdint.h>
#include <string.h>
#include "vl53l0x_def.h"   /* VL53L0X_DevData_t and other types */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t           I2cDevAddr;       /* 8-bit I2C address (shifted) */
    uint8_t           comms_type;       /* 1 = I2C                     */
    uint16_t          comms_speed_khz;  /* I2C clock speed in kHz      */
    VL53L0X_DevData_t Data;             /* Internal API data           */
} VL53L0X_Dev_t;

typedef VL53L0X_Dev_t *VL53L0X_DEV;
#define PALDevDataGet(Dev, field)             ((Dev)->Data.field)
#define PALDevDataSet(Dev, field, data)       ((Dev)->Data.field = (data))
#define VL53L0X_COPYSTRING(dst, src)          strcpy((dst), (src))
#define _LOG_FUNCTION_START(module, fmt, ...)
#define _LOG_FUNCTION_END(module, status, ...)
#define _LOG_FUNCTION_END_FMT(module, status, fmt, ...)
#define VL53L0X_DEFAULT_ADDR   0x52U   /* 7-bit addr 0x29 << 1 */
#define VL53L0X_I2C_TIMEOUT    100U    /* ms                    */

VL53L0X_Error VL53L0X_WriteMulti(VL53L0X_DEV Dev, uint8_t index, uint8_t *pdata, uint32_t count);
VL53L0X_Error VL53L0X_ReadMulti(VL53L0X_DEV Dev, uint8_t index, uint8_t *pdata, uint32_t count);
VL53L0X_Error VL53L0X_WrByte(VL53L0X_DEV Dev, uint8_t index, uint8_t data);
VL53L0X_Error VL53L0X_WrWord(VL53L0X_DEV Dev, uint8_t index, uint16_t data);
VL53L0X_Error VL53L0X_WrDWord(VL53L0X_DEV Dev, uint8_t index, uint32_t data);
VL53L0X_Error VL53L0X_RdByte(VL53L0X_DEV Dev, uint8_t index, uint8_t *data);
VL53L0X_Error VL53L0X_RdWord(VL53L0X_DEV Dev, uint8_t index, uint16_t *data);
VL53L0X_Error VL53L0X_RdDWord(VL53L0X_DEV Dev, uint8_t index, uint32_t *data);
VL53L0X_Error VL53L0X_UpdateByte(VL53L0X_DEV Dev, uint8_t index, uint8_t AndData, uint8_t OrData);
VL53L0X_Error VL53L0X_PollingDelay(VL53L0X_DEV Dev);

#ifdef __cplusplus
}
#endif

#endif /* VL53L0X_PLATFORM_H_ */

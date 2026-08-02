#ifndef __MOTOR_CONTROL_H__
#define __MOTOR_CONTROL_H__
#include "main.h"
#include <stdint.h>
#define MOTOR_PWM_MAX    2099
#define MOTOR_SPEED_STEP 210
#define SEMIAUTO_VEL_LENTA      1900
#define SEMIAUTO_DELAY_PINZA_MS  1500
#define SEMIAUTO_DELAY_RUEDA_MS  10000
#define SEMIAUTO_CRUCE_MS       3500

typedef enum {
    MOTOR_1 = 0,
    MOTOR_2,
    MOTOR_3,
    MOTOR_4,
    MOTOR_COUNT
} MotorId_t;


void Motor_Init(void);
void Motor_SetPulse(MotorId_t motor, uint16_t pulse);
void Motor_SetAllPulse(uint16_t pulse);
void Motor_SpeedInc(void);
void Motor_SpeedDec(void);
void Acoplar(void);
void Desacoplar(void);
void Acoplar1(void);
void Desacoplar1(void);
void Motor_Stop(void);
void Abrir_Pinza(void);
void Cerrar_Pinza(void);
uint16_t Motor_GetCurrentPulse(void);

#endif /* __MOTOR_CONTROL_H__ */

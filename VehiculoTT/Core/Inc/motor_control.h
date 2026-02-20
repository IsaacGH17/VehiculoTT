#ifndef __MOTOR_CONTROL_H__
#define __MOTOR_CONTROL_H__

#include "main.h"
#include <stdint.h>

/* ---- Configuracion PWM ---- */
#define MOTOR_PWM_MAX    2099   /* Period de TIM1 (0-2099 = 0-100% duty) */
#define MOTOR_SPEED_STEP 210   /* ~10% de incremento/decremento por paso  */

/* ---- Canales de motor (TIM1 CH1-CH4) ---- */
typedef enum {
    MOTOR_1 = 0,  /* TIM1_CH1 */
    MOTOR_2,      /* TIM1_CH2 */
    MOTOR_3,      /* TIM1_CH3 */
    MOTOR_4,      /* TIM1_CH4 */
    MOTOR_COUNT
} MotorId_t;

/* ---- API ---- */

/* Inicia los 4 canales PWM de TIM1 (llamar una vez despues de MX_TIM1_Init) */
void Motor_Init(void);

/* Establece duty cycle directo (0 a MOTOR_PWM_MAX) para un motor */
void Motor_SetPulse(MotorId_t motor, uint16_t pulse);

/* Establece el mismo duty cycle para los 4 motores */
void Motor_SetAllPulse(uint16_t pulse);

/* Incrementa la velocidad de todos los motores en un paso */
void Motor_SpeedInc(void);

/* Decrementa la velocidad de todos los motores en un paso */
void Motor_SpeedDec(void);

/* Paro: pone todos los motores a 0 */
void Motor_Stop(void);

/* Devuelve el pulso actual global */
uint16_t Motor_GetCurrentPulse(void);

#endif /* __MOTOR_CONTROL_H__ */

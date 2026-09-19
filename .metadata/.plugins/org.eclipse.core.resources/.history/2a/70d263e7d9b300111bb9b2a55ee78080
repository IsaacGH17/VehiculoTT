#include "motor_control.h"
#include "globals.h"
#include "main.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

volatile uint16_t current_pulse = 0;
volatile int16_t percentage_pulse = 0;
int i = 0;
volatile uint8_t dir_acoplar = 0;
volatile uint8_t dir_acoplar1 = 0;
volatile uint8_t pinza_abierta = 0;
volatile uint8_t pinza_abierta1 = 0;
static const uint32_t motor_channel[MOTOR_COUNT] = {
    TIM_CHANNEL_1,
    TIM_CHANNEL_2,
    TIM_CHANNEL_3,
    TIM_CHANNEL_4
};

void Motor_SetDirection(uint8_t reverse) {
    GPIO_PinState state = reverse ? GPIO_PIN_SET : GPIO_PIN_RESET;
    HAL_GPIO_WritePin(Direccion1_GPIO_Port, Direccion1_Pin, state);
    HAL_GPIO_WritePin(Direccion2_GPIO_Port, Direccion2_Pin, state);
    HAL_GPIO_WritePin(Direccion3_GPIO_Port, Direccion3_Pin, state);
    HAL_GPIO_WritePin(Direccion4_GPIO_Port, Direccion4_Pin, state);
}

void Motor_ApplySpeed(void) {
    int16_t speed = percentage_pulse;
    uint16_t pulse;

    if (speed > 100) {
        speed = 100;
    } else if (speed < -100) {
        speed = -100;
    }

    if (speed == 0) {
        Motor_SetAllPulse(0);
        Motor_SetDirection(0);
        return;
    }

    uint8_t reverse = (speed < 0) ? 1U : 0U;
    if (reverse) {
        speed = (int16_t)(-speed);
    }

    pulse = (uint16_t)(((uint32_t)speed * MOTOR_PWM_MAX) / 100U);

    Motor_SetAllPulse(0);
    Motor_SetDirection(reverse);
    Motor_SetAllPulse(pulse);
}

void Motor_SetSpeedPercentage(int16_t percentage) {
    if (percentage > 100) percentage = 100;
    if (percentage < -100) percentage = -100;
    percentage_pulse = percentage;
    Motor_ApplySpeed();
}

int16_t Motor_GetSpeedPercentage(void) {
    return percentage_pulse;
}

void Motor_Init(void) {
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 620);
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 620);
    Motor_SetDirection(0);
    Motor_SetAllPulse(0);
}

void Motor_SetPulse(MotorId_t motor, uint16_t pulse) {
    if (motor >= MOTOR_COUNT) return;
    if (pulse > MOTOR_PWM_MAX) pulse = MOTOR_PWM_MAX;

    __HAL_TIM_SET_COMPARE(&htim1, motor_channel[motor], pulse);
}

void Motor_SetAllPulse(uint16_t pulse) {
    if (pulse > MOTOR_PWM_MAX) pulse = MOTOR_PWM_MAX;
    current_pulse = pulse;

    for (uint8_t i = 0; i < MOTOR_COUNT; i++) {
        __HAL_TIM_SET_COMPARE(&htim1, motor_channel[i], pulse);
    }
}

void Motor_SpeedInc(void) {
    if (percentage_pulse < 100) {
        percentage_pulse += 10;
        if (percentage_pulse > 100) percentage_pulse = 100;
    }
    Motor_ApplySpeed();
}

void Acoplar(void){
    dir_acoplar = 1;
    HAL_GPIO_WritePin(A_Dir_GPIO_Port, A_Dir_Pin, GPIO_PIN_SET);
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 600);
}

void Desacoplar(void){
    dir_acoplar = 2;
    HAL_GPIO_WritePin(A_Dir_GPIO_Port, A_Dir_Pin, GPIO_PIN_RESET);
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 1700);
}

void Acoplar1(void){
    dir_acoplar1 = 1;
    HAL_GPIO_WritePin(A1_Dir_GPIO_Port, A1_Dir_Pin, GPIO_PIN_RESET);
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 2000);
}

void Desacoplar1(void){
    dir_acoplar1 = 2;
    HAL_GPIO_WritePin(A1_Dir_GPIO_Port, A1_Dir_Pin, GPIO_PIN_SET);
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 100);
}

void Motor_SpeedDec(void) {
    if (percentage_pulse > -100) {
        percentage_pulse -= 10;
        if (percentage_pulse < -100) percentage_pulse = -100;
    }
    Motor_ApplySpeed();
}

void Motor_Stop(void) {
    percentage_pulse = 0;
    Motor_SetAllPulse(0);
    Motor_SetDirection(0);
}

void Abrir_Pinza(void){
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 1290);
}

void Cerrar_Pinza(void){
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 620);
}
void Abrir_Pinza1(void){
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 1290);
}

void Cerrar_Pinza1(void){
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 620);
}

uint16_t Motor_GetCurrentPulse(void) {
    return current_pulse;
}

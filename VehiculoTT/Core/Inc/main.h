/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  ******************************************************************************
  */
/* USER CODE END Header */
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
void Error_Handler(void);
void FinalesCarrera_Process(void);

#define Abierto_Pin GPIO_PIN_14
#define Abierto_GPIO_Port GPIOC
#define Abierto_EXTI_IRQn EXTI15_10_IRQn
#define Cerrado_Pin GPIO_PIN_15
#define Cerrado_GPIO_Port GPIOC
#define Cerrado_EXTI_IRQn EXTI15_10_IRQn
#define ADC_tension_Pin GPIO_PIN_0
#define ADC_tension_GPIO_Port GPIOA
#define Servo2_Pin GPIO_PIN_1
#define Servo2_GPIO_Port GPIOA
#define Obstaculo1_Pin GPIO_PIN_2
#define Obstaculo1_GPIO_Port GPIOA
#define Obstaculo1_EXTI_IRQn EXTI2_IRQn
#define Abierto1_Pin GPIO_PIN_3
#define Abierto1_GPIO_Port GPIOA
#define Abierto1_EXTI_IRQn EXTI3_IRQn
#define Cerrado1_Pin GPIO_PIN_4
#define Cerrado1_GPIO_Port GPIOA
#define Cerrado1_EXTI_IRQn EXTI4_IRQn
#define Servo1_Pin GPIO_PIN_5
#define Servo1_GPIO_Port GPIOA
#define Acople1_Pin GPIO_PIN_6
#define Acople1_GPIO_Port GPIOA
#define Direccion1_Pin GPIO_PIN_7
#define Direccion1_GPIO_Port GPIOA
#define Direccion2_Pin GPIO_PIN_0
#define Direccion2_GPIO_Port GPIOB
#define Obstaculo2_Pin GPIO_PIN_12
#define Obstaculo2_GPIO_Port GPIOB
#define Obstaculo2_EXTI_IRQn EXTI15_10_IRQn
#define A1_Dir_Pin GPIO_PIN_15
#define A1_Dir_GPIO_Port GPIOB
#define Motor1_Pin GPIO_PIN_8
#define Motor1_GPIO_Port GPIOA
#define Motor2_Pin GPIO_PIN_9
#define Motor2_GPIO_Port GPIOA
#define Motor3_Pin GPIO_PIN_10
#define Motor3_GPIO_Port GPIOA
#define Motor4_Pin GPIO_PIN_11
#define Motor4_GPIO_Port GPIOA
#define Direccion3_Pin GPIO_PIN_12
#define Direccion3_GPIO_Port GPIOA
#define Direccion4_Pin GPIO_PIN_15
#define Direccion4_GPIO_Port GPIOA
#define A_Dir_Pin GPIO_PIN_4
#define A_Dir_GPIO_Port GPIOB
#define Acople_Pin GPIO_PIN_5
#define Acople_GPIO_Port GPIOB

#ifdef __cplusplus
}
#endif
#endif /* __MAIN_H */

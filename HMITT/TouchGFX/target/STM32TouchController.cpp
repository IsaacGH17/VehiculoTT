/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : STM32TouchController.cpp
  ******************************************************************************
  * This file was created by TouchGFX Generator 4.26.0. This file is only
  * generated once! Delete this file from your project and re-generate code
  * using STM32CubeMX or change this file manually to update it.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* USER CODE BEGIN STM32TouchController */

#include <STM32TouchController.hpp>
#include "ili9341.h"
#include "xpt2046.h"

extern "C" {
static void ConvXPTtoILI(uint16_t *x, uint16_t *y)
{
	int16_t tx, ty;
	// X: directo
	tx = (int16_t)(((int32_t)*x - XPT_XMIN) * GUI_WIDTH / XPT_WIDTH);
	tx = (tx < 0) ? 0 : tx;
	tx = (tx >= GUI_WIDTH) ? GUI_WIDTH-1 : tx;

	// Y: invertido para ROTATE_270 (el touch va en sentido contrario a la pantalla)
	ty = (int16_t)(((int32_t)XPT_YMAX - *y) * GUI_HEIGHT / XPT_HEIGHT);
	ty = (ty < 0) ? 0 : ty;
	ty = (ty >= GUI_HEIGHT) ? GUI_HEIGHT-1 : ty;

	*x = tx;
	*y = ty;
}
}

void STM32TouchController::init()
{
    /**
     * Initialize touch controller and driver
     *
     */
}

// Variables globales de calibración - accesibles via extern desde homeView.cpp
// Muestra los valores raw del touch para calibrar XPT_XMIN/MAX, YPT_YMIN/MAX
volatile uint16_t raw_touch_x = 0;
volatile uint16_t raw_touch_y = 0;

bool STM32TouchController::sampleTouch(int32_t& x, int32_t& y)
{
	static uint16_t prevx = GUI_WIDTH;
	static uint16_t prevy = GUI_HEIGHT;
	uint16_t intx, inty;
	XPT2046_Update(&intx, &inty);

	// Guarda siempre el valor crudo (aunque sea rechazado por IsReasonable)
	if (intx != 0 || inty != 0) {
		raw_touch_x = intx;
		raw_touch_y = inty;
	}

	if (XPT2046_IsReasonable(intx, inty)) {
		ConvXPTtoILI(&intx, &inty);
		if (intx != prevx || inty != prevy) {
			prevx = intx;
			prevy = inty;
			x = (int32_t)intx;
			y = (int32_t)inty;
			return true;
		}
	}
    return false;
}
/* USER CODE END STM32TouchController */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

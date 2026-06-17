#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "globals.h"
Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	if(modelListener)
	{
		modelListener->updateBat(vbat);
		modelListener->updatePWM(pwm);
		modelListener->updateDist(dist_mm);
		modelListener->updateRoll(roll);
		modelListener->updatePitch(pitch);
	}

}

#ifdef __cplusplus
extern "C" {
#endif
#include "protocolo.h"
extern UART_HandleTypeDef huart1;
#ifdef __cplusplus
}
#endif

void Model::solicitarModoSemi()
{
	static uint8_t tx_buf[8];
	uint8_t payload = PARAM_SEMIAUTO;
	uint16_t len = build_packet(tx_buf, CMD_MODO_OP, &payload, 1);
	if (huart1.gState == HAL_UART_STATE_READY)
	{
		HAL_UART_Transmit_DMA(&huart1, tx_buf, len);
	}
}

void Model::solicitarModoManual()
{
	static uint8_t tx_buf[8];
	uint8_t payload = PARAM_MANUAL;
	uint16_t len = build_packet(tx_buf, CMD_MODO_OP, &payload, 1);
	if (huart1.gState == HAL_UART_STATE_READY)
	{
		HAL_UART_Transmit_DMA(&huart1, tx_buf, len);
	}
}

#include "protocolo.h"
#include "motor_control.h"
#include <stdint.h>
#include <stdbool.h>
#include "main.h"
#include "cmsis_os.h"
#include "globals.h"

volatile uint8_t ruedas_abiertas  = 0;
volatile uint8_t ruedas1_abiertas = 0;  /* Estado par 2 de ruedas (A1) */
extern UART_HandleTypeDef huart1;

bool parse_byte(uint8_t byte, Packet_t *pkt, ParserCtx_t *ctx) {

    switch (ctx->state) {
        case ST_WAIT_START:
            if (byte == 0xAA) {
                ctx->state = ST_GET_CMD;
                ctx->calculated_checksum = 0;
            }
            break;

        case ST_GET_CMD:
            pkt->command = byte;
            ctx->calculated_checksum += byte;
            ctx->state = ST_GET_LEN;
            break;

        case ST_GET_LEN:
            pkt->length = byte;
            if (byte > MAX_PAYLOAD) {
                ctx->state = ST_WAIT_START;
                break;
            }
            ctx->calculated_checksum += byte;
            ctx->payload_idx = 0;
            if (pkt->length > 0) ctx->state = ST_GET_PAYLOAD;
            else ctx->state = ST_GET_CHECKSUM;
            break;

        case ST_GET_PAYLOAD:
            pkt->payload[ctx->payload_idx++] = byte;
            ctx->calculated_checksum += byte;
            if (ctx->payload_idx >= pkt->length) ctx->state = ST_GET_CHECKSUM;
            break;

        case ST_GET_CHECKSUM:
            pkt->checksum = byte;
            if (pkt->checksum == (uint8_t)(ctx->calculated_checksum & 0xFF)) {
                ctx->state = ST_WAIT_END;
            } else {
                ctx->state = ST_WAIT_START;
            }
            break;

        case ST_WAIT_END:
            ctx->state = ST_WAIT_START;
            if (byte == 0x55) return true;
            break;
    }
    return false;
}

void execute_command(Packet_t *pkt) {
    switch (pkt->command) {

        case CMD_MODO_OP:
            if (pkt->payload[0] == PARAM_MANUAL) {
                Motor_SetAllPulse(0);
                /* Cancelar modo semiautomático si estaba activo */
                if (semiAutoEvtHandle != NULL)
                    osEventFlagsSet(semiAutoEvtHandle, EVT_STOP_SEMI);
            } else if (pkt->payload[0] == PARAM_SEMIAUTO) {
                /* Iniciar tarea semiautomática */
                if (semiAutoEvtHandle != NULL)
                    osEventFlagsSet(semiAutoEvtHandle, EVT_START_SEMI);
            }
            break;

        case CMD_VELOCIDAD:
            if (pkt->payload[0] == PARAM_VEL_INC) {
                Motor_SpeedInc();
            } else if (pkt->payload[0] == PARAM_VEL_DEC) {
                Motor_SpeedDec();
            }
            break;

        case CMD_AVANCE_CTRL:
            if (Motor_GetCurrentPulse() == 0) {
                Motor_SetAllPulse(MOTOR_SPEED_STEP);
            }
            break;

        case CMD_PARO_EMERG:
            Motor_Stop();
            /* Abortar secuencia semiautomática */
            if (semiAutoEvtHandle != NULL)
                osEventFlagsSet(semiAutoEvtHandle, EVT_STOP_SEMI);
            /* Cierra la pinza y acopla ambas ruedas en Paro de Emergencia */
            Cerrar_Pinza();
            if (ruedas_abiertas) {
                Acoplar();
                ruedas_abiertas = 0;
            }
            if (ruedas1_abiertas) {
                Acoplar1();
                ruedas1_abiertas = 0;
            }
            break;

        case CMD_PARO:
            Motor_Stop();
            /* Abortar secuencia semiautomática */
            if (semiAutoEvtHandle != NULL)
                osEventFlagsSet(semiAutoEvtHandle, EVT_STOP_SEMI);
            break;

        case CMD_PINZAS:
           if(pkt->payload[0] == PARAM_CLOSE){
        	   Cerrar_Pinza();
           } else if(pkt->payload[0] == PARAM_OPEN){
        	   Abrir_Pinza();
           }

            break;
        case CMD_ACK_NACK:
        {
            uint16_t packet_size = 0;
            static uint8_t tx_buffer[20];
            uint8_t payload[1] = { (uint8_t)percentage_pulse };
            packet_size = build_packet(tx_buffer, RESP_SUCCESS, payload, 1);
            while (huart1.gState != HAL_UART_STATE_READY) {
                osDelay(1);
            }
            HAL_UART_Transmit_DMA(&huart1, tx_buffer, packet_size);
            break;
        }
        case CMD_PINON:
            break;

        case CMD_ACOPLE_RUEDAS:
            if (pkt->payload[0] == PARAM_OPEN) {
                if (!ruedas_abiertas) {
                    Desacoplar();
                    ruedas_abiertas = 1;
                }
                if (!ruedas1_abiertas) {
                    Desacoplar1();
                    ruedas1_abiertas = 1;
                }
            } else if (pkt->payload[0] == PARAM_CLOSE) {
                if (ruedas_abiertas) {
                    Acoplar();
                    ruedas_abiertas = 0;
                }
                if (ruedas1_abiertas) {
                    Acoplar1();
                    ruedas1_abiertas = 0;
                }
            }
            break;

        default:
            break;
    }
}

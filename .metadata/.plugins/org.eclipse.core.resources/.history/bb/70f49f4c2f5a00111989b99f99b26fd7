#include "protocolo.h"
#include "motor_control.h"
#include <stdint.h>
#include <stdbool.h>
#include "main.h"
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
            } else if (pkt->payload[0] == PARAM_SEMIAUTO) {
                Motor_SetAllPulse(MOTOR_SPEED_STEP);
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
            break;

        case CMD_PARO:
            Motor_Stop();
            break;

        case CMD_PINZAS:
           Servo_Pinza();
           if(pkt->payload[0] == PARAM_CLOSE){
        	   Servo_Pinza();
           } else if(pkt->payload[0] == PARAM_OPEN){
        	   Servo_Pinza();
           }

            break;

        case CMD_PINON:
            break;

        case CMD_ACOPLE_RUEDAS:
            break;

        default:
            break;
    }
}

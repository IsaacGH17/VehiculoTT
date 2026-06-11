#include "protocolo.h"
#include <stdint.h>
#include <stdbool.h>
#include "main.h"
#include "globals.h"
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

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
    if (pkt->command == CMD_TELE_SENSORS) {
        if (pkt->length >= 10) {
            uint16_t mm = (uint16_t)(((uint16_t)pkt->payload[0] << 8) | pkt->payload[1]);
            dist_mm = mm;

            uint16_t vbat_mv = (uint16_t)(((uint16_t)pkt->payload[2] << 8) | pkt->payload[3]);
            float v_volts = (float)vbat_mv / 100.0f;
            float porcentaje = ((v_volts - 5.6f) / (8.4f - 5.6f)) * 100.0f;
            if (porcentaje > 100.0f) porcentaje = 100.0f;
            if (porcentaje < 0.0f) porcentaje = 0.0f;
            vbat = porcentaje;

            int16_t ax_raw = (int16_t)(((uint16_t)pkt->payload[4] << 8) | pkt->payload[5]);
            int16_t ay_raw = (int16_t)(((uint16_t)pkt->payload[6] << 8) | pkt->payload[7]);
            int16_t az_raw = (int16_t)(((uint16_t)pkt->payload[8] << 8) | pkt->payload[9]);

            float Ax = (float)ax_raw / 1000.0f;
            float Ay = (float)ay_raw / 1000.0f;
            float Az = (float)az_raw / 1000.0f;

            roll = atan2f(Ay, Az) * 180.0f / M_PI;
            pitch = atan2f(-Ax, sqrtf(Ay*Ay + Az*Az)) * 180.0f / M_PI;
        }
    } else if (pkt->command == RESP_SUCCESS) {
        HAL_GPIO_WritePin(Rojo_GPIO_Port,    Rojo_Pin,    GPIO_PIN_RESET); /* Apagar Rojo */
        HAL_GPIO_WritePin(Amarillo_GPIO_Port, Amarillo_Pin, GPIO_PIN_RESET); /* Apagar Amarillo */
        HAL_GPIO_WritePin(Verde_GPIO_Port,   Verde_Pin,   GPIO_PIN_SET);   /* Encender Verde */
        if (pkt->length >= 1) {
            pwm = pkt->payload[0];
        }
    }
}

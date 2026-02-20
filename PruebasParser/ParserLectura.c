#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

typedef enum {
    CMD_MODO_OP        = 0x01,
    CMD_VELOCIDAD      = 0x02,
    CMD_DIRECCION      = 0x03,
    CMD_PARO_EMERG     = 0x04,
    CMD_PARO           = 0x05,
    CMD_AVANCE_CTRL    = 0x06,
    CMD_PINZAS         = 0x07,
    CMD_PINON          = 0x08,
    CMD_ACOPLE_RUEDAS  = 0x09
} Command_t;

typedef enum {
    PARAM_MANUAL       = 0x01,
    PARAM_SEMIAUTO     = 0x02,
    PARAM_VEL_INC      = 0x03,
    PARAM_VEL_DEC      = 0x04,
    PARAM_FORWARD      = 0x01,
    PARAM_BACKWARD     = 0x02,
    PARAM_OPEN         = 0x01,
    PARAM_CLOSE        = 0x02,
    PARAM_EXTEND       = 0x01,
    PARAM_RETRACT      = 0x02,
    PARAM_COUPLE       = 0x01,
    PARAM_DECOUPLE     = 0x02,
    PARAM_NONE         = 0x00
} Param_t;

#define MAX_PAYLOAD 10

typedef struct {
    uint8_t  command;
    uint8_t  length;
    uint8_t  payload[MAX_PAYLOAD];
    uint16_t checksum;
} Packet_t;

typedef enum {
    ST_WAIT_START,
    ST_GET_CMD,
    ST_GET_LEN,
    ST_GET_PAYLOAD,
    ST_GET_CHECKSUM,
    ST_WAIT_END
} State_t;

bool parse_byte(uint8_t byte, Packet_t *pkt) {
    static State_t state = ST_WAIT_START;
    static uint8_t payload_idx = 0;
    static uint16_t calculated_checksum = 0;

    switch (state) {
        case ST_WAIT_START:
            if (byte == 0xAA) {
                state = ST_GET_CMD;
                calculated_checksum = 0; 
            }
            break;

        case ST_GET_CMD:
            pkt->command = byte;
            calculated_checksum += byte;
            state = ST_GET_LEN;
            break;

        case ST_GET_LEN:
            pkt->length = byte;
            calculated_checksum += byte;
            payload_idx = 0;
            if (pkt->length > 0) state = ST_GET_PAYLOAD;
            else state = ST_GET_CHECKSUM;
            break;

        case ST_GET_PAYLOAD:
            pkt->payload[payload_idx++] = byte;
            calculated_checksum += byte;
            if (payload_idx >= pkt->length) state = ST_GET_CHECKSUM;
            break;

        case ST_GET_CHECKSUM:
            pkt->checksum = byte; 
            if (pkt->checksum == (uint8_t)(calculated_checksum & 0xFF)) {
                state = ST_WAIT_END;
            } else {
                state = ST_WAIT_START;
                printf("Error: Checksum inválido\n");
            }
            break;

        case ST_WAIT_END:
            state = ST_WAIT_START;
            if (byte == 0x55) return true; 
            break;
    }
    return false;
}

void execute_command(Packet_t *pkt) {
    printf("Ejecutando Comando: 0x%02X -> ", pkt->command);
    
    switch (pkt->command) {
        case CMD_MODO_OP:
            if (pkt->payload[0] == PARAM_MANUAL) printf("Cambiando a Modo MANUAL\n");
            else printf("Cambiando a Modo SEMIAUTO\n");
            break;
            
        case CMD_PARO_EMERG:
            printf("!!! PARO DE EMERGENCIA ACTIVADO !!!\n");
            break;
            
        case CMD_AVANCE_CTRL:
            if (pkt->payload[0] == PARAM_FORWARD) printf("Vehículo AVANZANDO\n");
            else printf("Vehículo RETROCEDIENDO\n");
            break;

        default:
            printf("Comando no reconocido\n");
            break;
    }
}

int main() {
    uint8_t raw_data[] = {0x01, 0xAA, 0x06, 0x01, 0x01, 0x08, 0x55, 0x02};
    Packet_t myPacket;
	int i = 0;
    for (i = 0; i < sizeof(raw_data); i++) {
        if (parse_byte(raw_data[i], &myPacket)) {
            execute_command(&myPacket);
        }
    }
    return 0;
}

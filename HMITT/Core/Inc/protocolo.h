#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__
#include <stdint.h>
#include <stdbool.h>
#include "main.h"
typedef enum {
    CMD_ACK_NACK       = 0x20,
    CMD_ERR_BATTERY    = 0x21,
    CMD_ERR_OVERCURRENT= 0x23,
    CMD_ERR_SENSOR     = 0x24,
    CMD_TELE_OBSTACLE  = 0x26,
    CMD_TELE_SENSORS   = 0x27
} FeedbackCmd_t;

typedef enum {
    RESP_SUCCESS       = 0x11,
    RESP_FAILURE       = 0x12
} Response_t;

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

typedef struct {
    State_t  state;
    uint8_t  payload_idx;
    uint16_t calculated_checksum;
} ParserCtx_t;

bool parse_byte(uint8_t byte, Packet_t *pkt, ParserCtx_t *ctx);
void execute_command(Packet_t *pkt);
uint16_t build_packet(uint8_t *buffer, uint8_t cmd, uint8_t *payload, uint8_t payload_len);
#endif

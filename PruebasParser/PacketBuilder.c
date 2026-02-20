
typedef enum {
    CMD_ACK_NACK       = 0x20,
    CMD_ERR_BATTERY    = 0x21,
    CMD_ERR_OVERCURRENT= 0x23,
    CMD_ERR_SENSOR     = 0x24,
    CMD_TELE_BATTERY   = 0x25,
    CMD_TELE_OBSTACLE  = 0x26,
    CMD_TELE_SENSORS   = 0x27
} FeedbackCmd_t;

typedef enum {
    RESP_SUCCESS       = 0x11,
    RESP_FAILURE       = 0x12
} Response_t;

uint16_t build_packet(uint8_t *buffer, uint8_t cmd, uint8_t *payload, uint8_t payload_len) {
    uint16_t idx = 0;
    uint8_t checksum = 0;
    buffer[idx++] = 0xAA;
    buffer[idx++] = cmd;
    checksum += cmd;
    buffer[idx++] = payload_len;
    checksum += payload_len;
    for (uint8_t i = 0; i < payload_len; i++) {
        buffer[idx++] = payload[i];
        checksum += payload[i];
    }
    buffer[idx++] = checksum; 
    buffer[idx++] = 0x55;

    return idx;
}
void send_battery_telemetry(void) {
    uint32_t adc_val = HAL_ADC_GetValue(&hadc1);
    uint16_t battery_mv = (uint16_t)((adc_val * 3300 * FACTOR_DIVISOR) / 4095);
    static uint8_t tx_buf[10]; 
    uint8_t payload[2];
    payload[0] = (uint8_t)(battery_mv >> 8); 
    payload[1] = (uint8_t)(battery_mv & 0xFF);
    uint16_t size = build_packet(tx_buf, CMD_TELE_BATTERY, payload, 2);
    if(huart2.gState == HAL_UART_STATE_READY) {
        HAL_UART_Transmit_DMA(&huart2, tx_buf, size);
    }
}

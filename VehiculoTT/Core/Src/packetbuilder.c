
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
#include <stdint.h>

uint8_t libptz_pack_packet_header(uint8_t sender_address, uint8_t receiver_address);
uint32_t libptz_pack_packet(uint8_t* payload, uint32_t payload_length, uint8_t* output_buffer, uint32_t output_buffer_length);
uint32_t libptz_encode_zoom_stop(uint8_t* output_buffer, uint32_t output_buffer_length);

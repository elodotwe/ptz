#include "ptz.h"
#include <string.h>

uint8_t libptz_pack_packet_header(uint8_t sender_address, uint8_t receiver_address) {
	return (sender_address << 4) + receiver_address + 0x80;
}

uint32_t libptz_pack_packet(uint8_t* payload, uint32_t payload_length, uint8_t* output_buffer, uint32_t output_buffer_length) {
	uint32_t output_length = payload_length + 2;
	if (output_buffer_length < output_length) {
		return 0;
	}
	memcpy(payload, output_buffer + 1, payload_length);
	output_buffer[0] = libptz_pack_packet_header(0, 0);
	output_buffer[output_length - 1] = 0xff;
	return output_length;
}

/**
* Writes bytes corresponding to a "zoom stop" command into output_buffer.
* Returns the number of bytes written to the buffer.
*/
uint32_t libptz_encode_zoom_stop(uint8_t* output_buffer, uint32_t output_buffer_length) {
	uint8_t zoom_stop[] = { 0x01, 0x04, 0x07, 0x00 };
	return libptz_pack_packet(zoom_stop, sizeof(zoom_stop), output_buffer, output_buffer_length);
}



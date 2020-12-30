#include "ptz.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void assert_equals_u32(uint32_t a, uint32_t b, char* message) {
	if (a != b) {
		printf("%d != %d: %s\n", a, b, message);
		abort();
	}
}

void assert_equals_u8buf(uint8_t* a, uint8_t* b, uint32_t size, char* message) {
	if (memcmp(a, b, size)) {
		printf("buffers not equal: %s\n", message);
		abort();
	}
}

int main() {
	printf("testing libptz\n");
	assert_equals_u32(0x80, libptz_pack_packet_header(0, 0), "packet header with 0 sender and receiver");
	assert_equals_u32(0xf7, libptz_pack_packet_header(7, 7), "packet header with 7 sender and receiver");
	uint8_t output_buffer[50];
	uint8_t payload_buffer[] = {0x12, 0x34, 0x56};
	uint32_t packed_length = libptz_pack_packet(payload_buffer, sizeof(payload_buffer), output_buffer, sizeof(output_buffer));
	assert_equals_u32(5, packed_length, "packed packet length with 3 payload bytes should be 5");
	uint8_t packed_goal[] = {0x80, 0x12, 0x34, 0x56, 0xff};
	assert_equals_u8buf(packed_goal, output_buffer, sizeof(packed_goal), "packed packet should have proper header and terminator");
	printf("all tests pass!\n");
	return 0;
}

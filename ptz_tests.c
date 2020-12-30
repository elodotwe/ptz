#include "ptz.h"
#include <stdio.h>
#include <stdlib.h>

void assert_equals(uint32_t a, uint32_t b, char* message) {
	if (a != b) {
		printf("%d != %d: %s\n", a, b, message);
		abort();
	}
}

int main() {
	printf("testing libptz\n");
	assert_equals(0x80, libptz_pack_packet_header(0, 0), "packet header with 0 sender and receiver");
	assert_equals(0xf7, libptz_pack_packet_header(7, 7), "packet header with 7 sender and receiver");
	printf("all tests pass!\n");
	return 0;
}

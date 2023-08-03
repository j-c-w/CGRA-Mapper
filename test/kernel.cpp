// Source is: /home/alex/.local/share/compy-Learn/1.0/libav/content/libavcodec/apedec.c

#include <stdint.h>
#include <stdio.h>


int
fn (int cf, int symbol, uint16_t * counts)
{
	for (int i = 0; i < cf; i ++) {
		counts[i] = counts[i] + 10;
	}
}

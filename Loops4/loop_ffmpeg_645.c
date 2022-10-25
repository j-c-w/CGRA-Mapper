// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/pcm.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint8_t uint8_t;

int
fn (const uint8_t * src, int32_t * dst_int32_t, int i, int n)
{
  for (i = 0; i < n; i++)
    {
      *dst_int32_t++ =
	((uint32_t) src[2] << 28) | (src[1] << 20) | (src[0] << 12) |
	((src[2] & 0x0F) << 8) | src[1];
      *dst_int32_t++ =
	((uint32_t) src[4] << 24) | (src[3] << 16) | ((src[2] & 0xF0) << 8) |
	(src[4] << 4) | (src[3] >> 4);
      src += 5;
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/tdsc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (uint8_t * dst, uint32_t bits, int k)
{
  for (k = 0; k < 32; k++)
    {
      dst[0] = !!(bits & 0x80000000);
      dst += 4;
      bits <<= 1;
    }
}

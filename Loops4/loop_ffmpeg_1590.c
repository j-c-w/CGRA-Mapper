// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/photocd.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * src2, int x, int width, uint8_t * dst,
    const uint8_t * src1)
{
  for (x = 0; x < width - 2; x += 2)
    {
      dst[x] = (src1[x] + src2[x] + 1) >> 1;
      dst[x + 1] = (src1[x] + src2[x] + src1[x + 2] + src2[x + 2] + 2) >> 2;
    }
}

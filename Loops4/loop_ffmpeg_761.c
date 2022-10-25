// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/input.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int width, int i, const uint8_t * src, int16_t * dst)
{
  for (i = 0; i < width; i++)
    {
      dst[i] = src[4 * i + 3] << 6 | src[4 * i + 3] >> 2;
    }
}

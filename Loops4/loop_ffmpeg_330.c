// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/vp9dsp_8bpp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * top, uint8_t v[63], const uint8_t * left, int i)
{
  for (i = 0; i < 32 - 2; i++)
    {
      v[i] = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
      v[32 + 1 + i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
    }
}

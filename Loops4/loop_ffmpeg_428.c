// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/vp9dsp_8bpp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * top, uint8_t v[22], const uint8_t * left, int i)
{
  for (i = 0; i < 8 - 2; i++)
    {
      v[i * 2] = (left[i + 1] + left[i + 0] + 1) >> 1;
      v[i * 2 + 1] = (left[i + 2] + left[i + 1] * 2 + left[i + 0] + 2) >> 2;
      v[8 * 2 + i] = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/vp9dsp_8bpp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * top, uint8_t ve[11], uint8_t vo[11], int i)
{
  for (i = 0; i < 8 - 1; i++)
    {
      ve[8 / 2 + i] = (top[i] + top[i + 1] + 1) >> 1;
      vo[8 / 2 + i] = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
    }
}

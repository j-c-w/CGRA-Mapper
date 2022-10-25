// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/vp9dsp_8bpp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * top, int i, uint8_t ve[7], uint8_t vo[7])
{
  for (i = 0; i < 8 - 2; i++)
    {
      ve[i] = (top[i] + top[i + 1] + 1) >> 1;
      vo[i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/vp9dsp_8bpp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * top, int i, uint8_t vo[23], uint8_t ve[23])
{
  for (i = 0; i < 16 - 1; i++)
    {
      ve[16 / 2 + i] = (top[i] + top[i + 1] + 1) >> 1;
      vo[16 / 2 + i] = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
    }
}

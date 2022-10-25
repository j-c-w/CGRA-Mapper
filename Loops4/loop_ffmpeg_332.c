// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/vp9dsp_8bpp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * left, int i, uint8_t ve[47], uint8_t vo[47])
{
  for (i = 0; i < 32 / 2 - 2; i++)
    {
      vo[i] =
	(left[i * 2 + 3] + left[i * 2 + 2] * 2 + left[i * 2 + 1] + 2) >> 2;
      ve[i] =
	(left[i * 2 + 4] + left[i * 2 + 3] * 2 + left[i * 2 + 2] + 2) >> 2;
    }
}

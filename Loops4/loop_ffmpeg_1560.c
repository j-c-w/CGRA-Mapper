// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_premultiply.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, const uint8_t * msrc, int x, const uint8_t * asrc, uint8_t * dst)
{
  for (x = 0; x < w; x++)
    {
      dst[x] =
	((((msrc[x] - 128) * (((asrc[x] >> 1) & 1) + asrc[x]))) >> 8) + 128;
    }
}

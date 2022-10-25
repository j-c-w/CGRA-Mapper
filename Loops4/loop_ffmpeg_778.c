// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/utvideodsp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * src_g, int g, int i, uint16_t * src_b, int width,
    uint16_t * src_r, int r, int b)
{
  for (i = 0; i < width; i++)
    {
      r = src_r[i];
      g = src_g[i];
      b = src_b[i];
      src_r[i] = (r + g - 0x200) & 0x3FF;
      src_b[i] = (b + g - 0x200) & 0x3FF;
    }
}

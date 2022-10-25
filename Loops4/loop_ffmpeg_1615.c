// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_extractplanes.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, int comp, int width, const uint8_t * src, uint8_t * dst, int step)
{
  for (x = 0; x < width; x++)
    {
      dst[x * 2] = src[x * step + comp * 2];
      dst[x * 2 + 1] = src[x * step + comp * 2 + 1];
    }
}

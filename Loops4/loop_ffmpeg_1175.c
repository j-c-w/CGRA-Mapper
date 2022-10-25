// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_xfade.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int width, const uint16_t * xf1, const uint16_t * xf0, const int z,
    uint16_t * dst)
{
  for (int x = 0; x < width; x++)
    {
      const int zx = z + x;
      const int zz = zx % width + width * (zx < 0);
      dst[x] = (zx > 0) && (zx < width) ? xf1[zz] : xf0[zz];
}}

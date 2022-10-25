// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/dsp/enc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int tmp[16], const uint8_t * ref, int i, const uint8_t * src)
{
  for (i = 0; i < 4; ++i, src += 32, ref += 32)
    {
      const int d0 = src[0] - ref[0];
      const int d1 = src[1] - ref[1];
      const int d2 = src[2] - ref[2];
      const int d3 = src[3] - ref[3];
      const int a0 = (d0 + d3);
      const int a1 = (d1 + d2);
      const int a2 = (d1 - d2);
      const int a3 = (d0 - d3);
      tmp[0 + i * 4] = (a0 + a1) * 8;
      tmp[1 + i * 4] = (a2 * 2217 + a3 * 5352 + 1812) >> 9;
      tmp[2 + i * 4] = (a0 - a1) * 8;
      tmp[3 + i * 4] = (a3 * 2217 - a2 * 5352 + 937) >> 9;
}}

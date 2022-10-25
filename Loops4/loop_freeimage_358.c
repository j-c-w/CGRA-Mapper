// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/dsp/dec.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int tmp[16], int i, int16_t * out)
{
  for (i = 0; i < 4; ++i)
    {
      const int dc = tmp[0 + i * 4] + 3;
      const int a0 = dc + tmp[3 + i * 4];
      const int a1 = tmp[1 + i * 4] + tmp[2 + i * 4];
      const int a2 = tmp[1 + i * 4] - tmp[2 + i * 4];
      const int a3 = dc - tmp[3 + i * 4];
      out[0] = (a0 + a1) >> 3;
      out[16] = (a3 + a2) >> 3;
      out[32] = (a0 - a1) >> 3;
      out[48] = (a3 - a2) >> 3;
      out += 64;
}}

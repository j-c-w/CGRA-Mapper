// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/dsp/enc.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (int32_t tmp[16], int i, int16_t * out)
{
  for (i = 0; i < 4; ++i)
    {
      const int a0 = (tmp[0 + i] + tmp[8 + i]);
      const int a1 = (tmp[4 + i] + tmp[12 + i]);
      const int a2 = (tmp[4 + i] - tmp[12 + i]);
      const int a3 = (tmp[0 + i] - tmp[8 + i]);
      const int b0 = a0 + a1;
      const int b1 = a3 + a2;
      const int b2 = a3 - a2;
      const int b3 = a0 - a1;
      out[0 + i] = b0 >> 1;
      out[4 + i] = b1 >> 1;
      out[8 + i] = b2 >> 1;
      out[12 + i] = b3 >> 1;
}}

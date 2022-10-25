// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/dsp/dec.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int tmp[16], int i, const int16_t * in)
{
  for (i = 0; i < 4; ++i)
    {
      const int a0 = in[0 + i] + in[12 + i];
      const int a1 = in[4 + i] + in[8 + i];
      const int a2 = in[4 + i] - in[8 + i];
      const int a3 = in[0 + i] - in[12 + i];
      tmp[0 + i] = a0 + a1;
      tmp[8 + i] = a0 - a1;
      tmp[4 + i] = a3 + a2;
      tmp[12 + i] = a3 - a2;
}}

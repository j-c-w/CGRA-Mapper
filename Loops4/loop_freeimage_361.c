// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/dsp/enc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int tmp[16], int i, const uint8_t * in)
{
  for (i = 0; i < 4; ++i, in += 32)
    {
      const int a0 = in[0] + in[2];
      const int a1 = in[1] + in[3];
      const int a2 = in[1] - in[3];
      const int a3 = in[0] - in[2];
      tmp[0 + i * 4] = a0 + a1;
      tmp[1 + i * 4] = a3 + a2;
      tmp[2 + i * 4] = a3 - a2;
      tmp[3 + i * 4] = a0 - a1;
}}

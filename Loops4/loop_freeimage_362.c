// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/dsp/enc.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (int32_t tmp[16], int i, const int16_t * in)
{
  for (i = 0; i < 4; ++i, in += 64)
    {
      const int a0 = (in[0 * 16] + in[2 * 16]);
      const int a1 = (in[1 * 16] + in[3 * 16]);
      const int a2 = (in[1 * 16] - in[3 * 16]);
      const int a3 = (in[0 * 16] - in[2 * 16]);
      tmp[0 + i * 4] = a0 + a1;
      tmp[1 + i * 4] = a3 + a2;
      tmp[2 + i * 4] = a3 - a2;
      tmp[3 + i * 4] = a0 - a1;
}}

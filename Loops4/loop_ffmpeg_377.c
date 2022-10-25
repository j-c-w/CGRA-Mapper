// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/rv34dsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * block, int i, int temp[16])
{
  for (i = 0; i < 4; i++)
    {
      const int z0 = 39 * (temp[4 * 0 + i] + temp[4 * 2 + i]);
      const int z1 = 39 * (temp[4 * 0 + i] - temp[4 * 2 + i]);
      const int z2 = 21 * temp[4 * 1 + i] - 51 * temp[4 * 3 + i];
      const int z3 = 51 * temp[4 * 1 + i] + 21 * temp[4 * 3 + i];
      block[i * 4 + 0] = (z0 + z3) >> 11;
      block[i * 4 + 1] = (z1 + z2) >> 11;
      block[i * 4 + 2] = (z1 - z2) >> 11;
      block[i * 4 + 3] = (z0 - z3) >> 11;
}}

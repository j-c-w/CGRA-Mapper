// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/rv34dsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * block, int *temp, int i)
{
  for (i = 0; i < 4; i++)
    {
      const int z0 = 13 * (block[i + 4 * 0] + block[i + 4 * 2]);
      const int z1 = 13 * (block[i + 4 * 0] - block[i + 4 * 2]);
      const int z2 = 7 * block[i + 4 * 1] - 17 * block[i + 4 * 3];
      const int z3 = 17 * block[i + 4 * 1] + 7 * block[i + 4 * 3];
      temp[4 * i + 0] = z0 + z3;
      temp[4 * i + 1] = z1 + z2;
      temp[4 * i + 2] = z1 - z2;
      temp[4 * i + 3] = z0 - z3;
}}

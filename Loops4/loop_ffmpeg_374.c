// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/svq3.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * block, int i)
{
  for (i = 0; i < 4; i++)
    {
      const int z0 = 13 * (block[0 + 4 * i] + block[2 + 4 * i]);
      const int z1 = 13 * (block[0 + 4 * i] - block[2 + 4 * i]);
      const int z2 = 7 * block[1 + 4 * i] - 17 * block[3 + 4 * i];
      const int z3 = 17 * block[1 + 4 * i] + 7 * block[3 + 4 * i];
      block[0 + 4 * i] = z0 + z3;
      block[1 + 4 * i] = z1 + z2;
      block[2 + 4 * i] = z1 - z2;
      block[3 + 4 * i] = z0 - z3;
}}

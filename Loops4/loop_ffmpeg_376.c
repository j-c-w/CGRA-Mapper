// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/svq3.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * input, int i, int temp[16])
{
  for (i = 0; i < 4; i++)
    {
      const int z0 = 13 * (input[4 * i + 0] + input[4 * i + 2]);
      const int z1 = 13 * (input[4 * i + 0] - input[4 * i + 2]);
      const int z2 = 7 * input[4 * i + 1] - 17 * input[4 * i + 3];
      const int z3 = 17 * input[4 * i + 1] + 7 * input[4 * i + 3];
      temp[4 * i + 0] = z0 + z3;
      temp[4 * i + 1] = z1 + z2;
      temp[4 * i + 2] = z1 - z2;
      temp[4 * i + 3] = z0 - z3;
}}

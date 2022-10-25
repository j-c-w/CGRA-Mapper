// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/h264idct.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * input, int i, int temp[16])
{
  for (i = 0; i < 4; i++)
    {
      const int z0 = input[4 * i + 0] + input[4 * i + 1];
      const int z1 = input[4 * i + 0] - input[4 * i + 1];
      const int z2 = input[4 * i + 2] - input[4 * i + 3];
      const int z3 = input[4 * i + 2] + input[4 * i + 3];
      temp[4 * i + 0] = z0 + z3;
      temp[4 * i + 1] = z0 - z3;
      temp[4 * i + 2] = z1 - z2;
      temp[4 * i + 3] = z1 + z2;
}}

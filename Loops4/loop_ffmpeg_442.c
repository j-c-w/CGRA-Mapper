// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/cavsdsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t (*src)[8], int i)
{
  for (i = 0; i < 8; i++)
    {
      const int a0 = 3 * src[i][1] - 2 * src[i][7];
      const int a1 = 3 * src[i][3] + 2 * src[i][5];
      const int a2 = 2 * src[i][3] - 3 * src[i][5];
      const int a3 = 2 * src[i][1] + 3 * src[i][7];
      const int b4 = 2 * (a0 + a1 + a3) + a1;
      const int b5 = 2 * (a0 - a1 + a2) + a0;
      const int b6 = 2 * (a3 - a2 - a1) + a3;
      const int b7 = 2 * (a0 - a2 - a3) - a2;
      const int a7 = 4 * src[i][2] - 10 * src[i][6];
      const int a6 = 4 * src[i][6] + 10 * src[i][2];
      const int a5 = 8 * (src[i][0] - src[i][4]) + 4;
      const int a4 = 8 * (src[i][0] + src[i][4]) + 4;
      const int b0 = a4 + a6;
      const int b1 = a5 + a7;
      const int b2 = a5 - a7;
      const int b3 = a4 - a6;
      src[i][0] = (b0 + b4) >> 3;
      src[i][1] = (b1 + b5) >> 3;
      src[i][2] = (b2 + b6) >> 3;
      src[i][3] = (b3 + b7) >> 3;
      src[i][4] = (b3 - b7) >> 3;
      src[i][5] = (b2 - b6) >> 3;
      src[i][6] = (b1 - b5) >> 3;
      src[i][7] = (b0 - b4) >> 3;
}}

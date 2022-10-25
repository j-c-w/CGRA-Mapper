// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/vc1dsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * bottom, int d1, int i, int d, int16_t * top, int c, int a,
    int d2, int rnd1, int b)
{
  int rnd2 = 4;
  for (i = 0; i < 8; i++)
    {
      a = top[48];
      b = top[56];
      c = bottom[0];
      d = bottom[8];
      d1 = a - d;
      d2 = a - d + b - c;
      top[48] = ((a * 8) - d1 + rnd1) >> 3;
      top[56] = ((b * 8) - d2 + rnd2) >> 3;
      bottom[0] = ((c * 8) + d2 + rnd1) >> 3;
      bottom[8] = ((d * 8) + d1 + rnd2) >> 3;
      bottom++;
      top++;
      rnd2 = 7 - rnd2;
      rnd1 = 7 - rnd1;
    }
}

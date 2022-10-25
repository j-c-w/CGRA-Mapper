// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mpegaudioenc_float.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, int tmp[64], short *q, int sum, short *p)
{
  for (i = 0; i < 64; i++)
    {
      sum = p[0 * 64] * q[0 * 64];
      sum += p[1 * 64] * q[1 * 64];
      sum += p[2 * 64] * q[2 * 64];
      sum += p[3 * 64] * q[3 * 64];
      sum += p[4 * 64] * q[4 * 64];
      sum += p[5 * 64] * q[5 * 64];
      sum += p[6 * 64] * q[6 * 64];
      sum += p[7 * 64] * q[7 * 64];
      tmp[i] = sum;
      p++;
      q++;
    }
}

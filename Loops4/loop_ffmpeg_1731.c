// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/speexdec.c

#include <stdint.h>
#include <stdio.h>






int
fn (float xout1, float xout2, float *pw, float x_freq[10], float xin2,
    float xin1, float *n0, const int m)
{
  int i2 = 0;
  for (int i = 0; i < m; i++, i2 += 2)
    {
      n0 = pw + (i * 4);
      xout1 = xin1 + 2.f * x_freq[i2] * n0[0] + n0[1];
      xout2 = xin2 + 2.f * x_freq[i2 + 1] * n0[2] + n0[3];
      n0[1] = n0[0];
      n0[3] = n0[2];
      n0[0] = xin1;
      n0[2] = xin2;
      xin1 = xout1;
      xin2 = xout2;
}}

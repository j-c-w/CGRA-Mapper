// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/opusdsp.c

#include <stdint.h>
#include <stdio.h>






int
fn (float *data, float x3, float x4, int period, const float g2, float x1,
    const float g0, float x2, int len, const float g1)
{
  for (int i = 0; i < len; i++)
    {
      float x0 = data[i - period + 2];
      data[i] += g0 * x2 + g1 * (x1 + x3) + g2 * (x0 + x4);
      x4 = x3;
      x3 = x2;
      x2 = x1;
      x1 = x0;
}}

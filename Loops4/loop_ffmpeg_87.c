// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/sbrdsp.c

#include <stdint.h>
#include <stdio.h>






int
fn (float (*x)[2], int i, float sum0, int n)
{
  float sum1 = 0.0f;
  for (i = 0; i < n; i += 2)
    {
      sum0 += x[i + 0][0] * x[i + 0][0];
      sum1 += x[i + 0][1] * x[i + 0][1];
      sum0 += x[i + 1][0] * x[i + 1][0];
      sum1 += x[i + 1][1] * x[i + 1][1];
    }
}

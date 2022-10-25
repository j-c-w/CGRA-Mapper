// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/sbrdsp.c

#include <stdint.h>
#include <stdio.h>






int
fn (float imag_sum1, int i, float imag_sum2, const float (*x)[2],
    float real_sum2, float real_sum1)
{
  float real_sum0 = 0.0f;
  for (i = 1; i < 38; i++)
    {
      real_sum0 += x[i][0] * x[i][0] + x[i][1] * x[i][1];
      real_sum1 += x[i][0] * x[i + 1][0] + x[i][1] * x[i + 1][1];
      imag_sum1 += x[i][0] * x[i + 1][1] - x[i][1] * x[i + 1][0];
      real_sum2 += x[i][0] * x[i + 2][0] + x[i][1] * x[i + 2][1];
      imag_sum2 += x[i][0] * x[i + 2][1] - x[i][1] * x[i + 2][0];
    }
}

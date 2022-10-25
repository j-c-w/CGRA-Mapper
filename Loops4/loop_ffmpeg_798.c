// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/sbrdsp_fixed.c

#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (int i, int lag, int64_t accu_im, int64_t accu_re, const int (*x)[2])
{
  for (i = 1; i < 38; i++)
    {
      accu_re += (uint64_t) x[i][0] * x[i + lag][0];
      accu_re += (uint64_t) x[i][1] * x[i + lag][1];
      accu_im += (uint64_t) x[i][0] * x[i + lag][1];
      accu_im -= (uint64_t) x[i][1] * x[i + lag][0];
    }
}

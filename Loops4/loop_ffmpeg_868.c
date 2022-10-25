// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/sbrdsp_fixed.c

#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (int i, int start, int end, int (*X_high)[2], int alpha[4], int64_t accu,
    const int (*X_low)[2])
{
  for (i = start; i < end; i++)
    {
      accu = (int64_t) X_low[i][0] * 0x20000000;
      accu += (int64_t) X_low[i - 2][0] * alpha[0];
      accu -= (int64_t) X_low[i - 2][1] * alpha[1];
      accu += (int64_t) X_low[i - 1][0] * alpha[2];
      accu -= (int64_t) X_low[i - 1][1] * alpha[3];
      X_high[i][0] = (int) ((accu + 0x10000000) >> 29);
      accu = (int64_t) X_low[i][1] * 0x20000000;
      accu += (int64_t) X_low[i - 2][1] * alpha[0];
      accu += (int64_t) X_low[i - 2][0] * alpha[1];
      accu += (int64_t) X_low[i - 1][1] * alpha[2];
      accu += (int64_t) X_low[i - 1][0] * alpha[3];
      X_high[i][1] = (int) ((accu + 0x10000000) >> 29);
}}

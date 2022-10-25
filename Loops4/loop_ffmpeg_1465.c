// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/g723_1enc.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int64_t int64_t;

int
fn (int m, int16_t * iir_coef, int n, int16_t * src, int16_t * fir_coef,
    int64_t filter, int16_t * dest)
{
  for (n = 1; n <= 10; n++)
    {
      filter -= fir_coef[n - 1] * src[m - n] - iir_coef[n - 1] * dest[m - n];
    }
}

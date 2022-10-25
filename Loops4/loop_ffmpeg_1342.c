// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/apedec.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint32_t uint32_t;

int
fn (int32_t sign, int32_t dotprod, uint32_t coeffs[8], int32_t delay[8],
    int j)
{
  for (j = 7; j >= 0; j--)
    {
      dotprod += delay[j] * coeffs[j];
      coeffs[j] += ((delay[j] >> 31) | 1) * sign;
    }
}

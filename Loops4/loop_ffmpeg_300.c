// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/hevcdsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * coeffs, int j, int i, int coeff)
{
  for (i = 0; i < 16; i++)
    {
      coeffs[i + j * 16] = coeff;
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dca_lbr.c

#include <stdint.h>
#include <stdio.h>






int
fn (int j, float *coeff, int i, float rc)
{
  for (j = 0; j < (i + 1) / 2; j++)
    {
      float tmp1 = coeff[j];
      float tmp2 = coeff[i - j - 1];
      coeff[j] = tmp1 + rc * tmp2;
      coeff[i - j - 1] = tmp2 + rc * tmp1;
}}

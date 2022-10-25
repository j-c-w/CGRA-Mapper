// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/alacdsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int decorr_left_weight, int i, int nb_samples, int32_t ** buffer,
    int decorr_shift)
{
  for (i = 0; i < nb_samples; i++)
    {
      int32_t a, b;
      a = buffer[0][i];
      b = buffer[1][i];
      a -= (int) (b * (unsigned) decorr_left_weight) >> decorr_shift;
      b += a;
      buffer[0][i] = b;
      buffer[1][i] = a;
}}

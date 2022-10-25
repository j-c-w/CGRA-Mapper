// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ilbcdec.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int coefficients_length, int16_t * data_out, int j,
    const int16_t * coefficients)
{
  int sum = 0;
  for (j = coefficients_length - 1; j > 0; j--)
    {
      sum += (unsigned) (coefficients[j] * data_out[i - j]);
}}

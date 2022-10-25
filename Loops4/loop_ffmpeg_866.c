// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswresample/resample.c

#include <stdint.h>
#include <stdio.h>






int
fn (const double *coeff, int i, double x, double sum, int size)
{
  for (i = size - 2; i >= 0; --i)
    {
      sum *= x;
      sum += coeff[i];
    }
}

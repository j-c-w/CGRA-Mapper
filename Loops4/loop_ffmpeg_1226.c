// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswresample/rematrix.c

#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;

int
fn (int i, ptrdiff_t stride, double *matrix_param, int j,
    double rematrix_volume)
{
  for (j = 0; j < 64; j++)
    {
      matrix_param[stride * i + j] *= rematrix_volume;
    }
}

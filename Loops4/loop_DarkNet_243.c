// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/blas.c

#include <stdint.h>
#include <stdio.h>






int
fn (int spatial, float *x, int i, float *dx, int b, int f, float sum,
    int filters)
{
  for (f = 0; f < filters; ++f)
    {
      int index = b * filters * spatial + f * spatial + i;
      x[index] /= sum;
      dx[index] = (1 - x[index]) / sum;
}}

// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/batchnorm_layer.c

#include <stdint.h>
#include <stdio.h>






int
fn (int spatial, int j, float *x, int i, float *mean, float *delta, int k,
    int filters, float *variance_delta)
{
  for (k = 0; k < spatial; ++k)
    {
      int index = j * filters * spatial + i * spatial + k;
      variance_delta[i] += delta[index] * (x[index] - mean[i]);
}}

// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/blas.c

#include <stdint.h>
#include <stdio.h>






int
fn (int j, int h2, float s1, int i, int w1, int k, int w2, float *add, int b,
    int c2, float *out, int h1, int c1, int minw, int sample, int stride,
    float s2)
{
  for (i = 0; i < minw; ++i)
    {
      int out_index = i * sample + w2 * (j * sample + h2 * (k + c2 * b));
      int add_index = i * stride + w1 * (j * stride + h1 * (k + c1 * b));
      out[out_index] = s1 * out[out_index] + s2 * add[add_index];
}}

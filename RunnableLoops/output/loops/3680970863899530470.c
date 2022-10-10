#include <stdint.h>
#include <stdio.h>






int
fn (float *exc_out, int start, float *exc, int nsf, float pitch_coef)
{
  for (int i = 0; i < nsf; i++)
    {
      exc_out[i] = exc[i - start] * pitch_coef;
      exc[i] = exc_out[i];
}}

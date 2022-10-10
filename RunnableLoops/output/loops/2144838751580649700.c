#include <stdint.h>
#include <stdio.h>






int
fn (double *dst, double w1, double level_out, const double a1,
    const double b1, const double b2, double w2, const double a0,
    double level_in, const double a2, int nb_samples, const double *src)
{
  for (int i = 0; i < nb_samples; i++)
    {
      double n = src[i] * level_in;
      double tmp = n - w1 * b1 - w2 * b2;
      double out = tmp * a0 + w1 * a1 + w2 * a2;
      w2 = w1;
      w1 = tmp;
      dst[i] = out * level_out;
}}

#include <stdint.h>
#include <stdio.h>






int
fn (double *dst, double w1, double w2, double a1, double b2, double b0,
    double a2, int nb_samples, double b1, const double *src)
{
  for (int n = 0; n < nb_samples; n++)
    {
      double side = src[n];
      double oside = side * b0 + w1;
      w1 = b1 * side + w2 + a1 * oside;
      w2 = b2 * side + a2 * oside;
      dst[n] = oside;
}}

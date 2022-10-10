#include <stdint.h>
#include <stdio.h>






int
fn (const double b0, double *dst, const double a1, const double b1,
    const double b2, double z1, double z2, const double a2, int nb_samples,
    const double *src)
{
  for (int n = 0; n + 1 < nb_samples; n++)
    {
      double in = src[n];
      double out;
      out = in * b0 + z1;
      z1 = b1 * in + z2 + a1 * out;
      z2 = b2 * in + a2 * out;
      dst[n] = out;
      n++;
      in = src[n];
      out = in * b0 + z1;
      z1 = b1 * in + z2 + a1 * out;
      z2 = b2 * in + a2 * out;
      dst[n] = out;
}}

#include <stdint.h>
#include <stdio.h>






int
fn (const double *k, double n1, const int nb_stages, double n0, double p0,
    const double *v, double *x)
{
  double out = 0.;
  for (int i = nb_stages - 1; i >= 0; i--)
    {
      n0 = n1 - k[i] * x[i];
      p0 = n0 * k[i] + x[i];
      out += p0 * v[i + 1];
      x[i] = p0;
      n1 = n0;
}}

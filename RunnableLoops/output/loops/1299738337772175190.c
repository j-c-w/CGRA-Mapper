#include <stdint.h>
#include <stdio.h>






int
fn (int length, double w1, double *y, double a1, double b2, double *x,
    double a2, double b0, double b1)
{
  double w2 = 0.;
  for (int n = 0; n < length; n++)
    {
      double out, in = x[n];
      y[n] = out = in * b0 + w1;
      w1 = b1 * in + w2 + a1 * out;
      w2 = b2 * in + a2 * out;
}}

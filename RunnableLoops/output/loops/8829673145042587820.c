#include <stdint.h>
#include <stdio.h>






int
fn (float *coeff, const float *inbuf, int i, double fac, float gamma)
{
  for (i = 0; i < 10; i++)
    {
      coeff[i] = inbuf[i] * fac;
      fac *= gamma;
    }
}

#include <stdint.h>
#include <stdio.h>






int
fn (int i, const float *lpc, float fac, int size, float *out, float gamma)
{
  for (i = 0; i < size; i++)
    {
      out[i] = lpc[i] * fac;
      fac *= gamma;
    }
}

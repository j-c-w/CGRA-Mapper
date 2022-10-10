#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *lpc)
{
  double bandwidth_expansion_coeff = 0.9883;
  for (i = 0; i < 10; i++)
    {
      lpc[i] *= bandwidth_expansion_coeff;
      bandwidth_expansion_coeff *= 0.9883;
    }
}

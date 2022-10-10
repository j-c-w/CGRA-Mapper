#include <stdint.h>
#include <stdio.h>






int
fn (double x, int i, const double *coeff, double sum, int size)
{
  for (i = size - 2; i >= 0; --i)
    {
      sum *= x;
      sum += coeff[i];
    }
}

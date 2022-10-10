#include <stdint.h>
#include <stdio.h>






int
fn (double *ptr, int n, const int nb_samples, double *dst)
{
  for (n = 0; n < nb_samples; n++)
    {
      ptr[n] += dst[n];
    }
}

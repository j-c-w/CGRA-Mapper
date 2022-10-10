#include <stdint.h>
#include <stdio.h>






int
fn (const int nb_samples, double *ptr, int n, double *dst)
{
  for (n = 0; n < nb_samples; n++)
    {
      ptr[n] += dst[n];
    }
}

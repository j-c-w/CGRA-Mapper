#include <stdint.h>
#include <stdio.h>






int
fn (const double *median, const int *hist, int i, double err,
    double sum_sq_err)
{
  for (i = 0; i < (3 * 256); i++)
    {
      err = median[i] - (double) hist[i];
      sum_sq_err += err * err;
}}

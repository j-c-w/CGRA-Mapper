#include <stdint.h>
#include <stdio.h>






int
fn (int len, int i, int j, const double *data, double sum0)
{
  double sum1 = 1.0;
  for (i = j; i < len; i++)
    {
      sum0 += data[i] * data[i - j];
      sum1 += data[i] * data[i - j - 1];
    }
}

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (double w, int len, int i, const int32_t * data, int n2, double *w_data,
    double c)
{
  for (i = 0; i < n2; i++)
    {
      w = c - i - 1.0;
      w = 1.0 - (w * w);
      w_data[i] = data[i] * w;
      w_data[len - 1 - i] = data[len - 1 - i] * w;
    }
}

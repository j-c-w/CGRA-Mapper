#include <stdint.h>
#include <stdio.h>






int
fn (int j, int i, int len, const double *data)
{
  double sum = 1.0;
  for (i = j - 1; i < len; i += 2)
    {
      sum += data[i] * data[i - j] + data[i + 1] * data[i - j + 1];
    }
}

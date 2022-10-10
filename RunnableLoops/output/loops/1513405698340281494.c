#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (int filterSize, int64_t * filter, int i, int j, int64_t sum)
{
  for (j = 0; j < filterSize; j++)
    {
      sum += filter[i * filterSize + j];
    }
}

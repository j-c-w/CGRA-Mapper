#include <stdint.h>
#include <stdio.h>






int
fn (double mean, int cut, int x, int count, double *values)
{
  for (x = cut; x < count - cut; x++)
    {
      mean += values[x];
    }
}

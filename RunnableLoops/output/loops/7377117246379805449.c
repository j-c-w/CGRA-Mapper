#include <stdint.h>
#include <stdio.h>






int
fn (int *z, int k)
{
  for (k = 1; k < 32; k++)
    {
      z[64 + 2 * k] = -z[64 - k];
      z[64 + 2 * k + 1] = z[k + 1];
    }
}

#include <stdint.h>
#include <stdio.h>






int
fn (int i, double *lpc_in, int order, double scale)
{
  for (i = 0; i < order; i++)
    {
      lpc_in[i] *= scale;
    }
}

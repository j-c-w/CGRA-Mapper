#include <stdint.h>
#include <stdio.h>






int
fn (int i, int order, double scale, double *lpc_in)
{
  for (i = 0; i < order; i++)
    {
      lpc_in[i] *= scale;
    }
}

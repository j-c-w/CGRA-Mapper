#include <stdint.h>
#include <stdio.h>






int
fn (const float *lpc_in, float *lpc_out, int order, float tmp, float gamma)
{
  for (int i = 0; i < order; i++)
    {
      lpc_out[i] = tmp * lpc_in[i];
      tmp *= gamma;
}}

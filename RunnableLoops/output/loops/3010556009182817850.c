#include <stdint.h>
#include <stdio.h>






int
fn (int i, float gain_scale_factor, int size, float *out, float mem,
    const float *in, float alpha)
{
  for (i = 0; i < size; i++)
    {
      mem = alpha * mem + gain_scale_factor;
      out[i] = in[i] * mem;
    }
}

#include <stdint.h>
#include <stdio.h>






int
fn (float step, int i, int size, float v2, float *out)
{
  for (i = 0; i < size; i++)
    {
      v2 += step;
      out[i] = v2;
    }
}

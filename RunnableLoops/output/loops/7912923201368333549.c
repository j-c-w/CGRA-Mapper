#include <stdint.h>
#include <stdio.h>






int
fn (float *buf, int i, float *out_ptr)
{
  for (i = 0; i < 18; i++)
    {
      *out_ptr = buf[4 * i];
      buf[4 * i] = 0;
      out_ptr += 32;
    }
}

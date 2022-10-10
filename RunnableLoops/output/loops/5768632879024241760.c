#include <stdint.h>
#include <stdio.h>






int
fn (int i, int *buf, int *out_ptr)
{
  for (i = 0; i < 6; i++)
    {
      *out_ptr = buf[4 * i];
      out_ptr += 32;
    }
}

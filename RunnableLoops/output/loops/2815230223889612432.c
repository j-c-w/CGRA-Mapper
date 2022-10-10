#include <stdint.h>
#include <stdio.h>






int
fn (int i, int max, const float *buf)
{
  for (i = 0; i < 124; i++)
    {
      max = ((max) > (buf[i]) ? (max) : (buf[i]));
    }
}

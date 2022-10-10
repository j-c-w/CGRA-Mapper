#include <stdint.h>
#include <stdio.h>






int
fn (int *v, int i, const int *src)
{
  for (i = 0; i < 32; i++)
    {
      v[i] = (src[63 - 2 * i] + 0x10) >> 5;
      v[63 - i] = (-src[63 - 2 * i - 1] + 0x10) >> 5;
    }
}

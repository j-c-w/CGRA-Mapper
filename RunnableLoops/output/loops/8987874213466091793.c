#include <stdint.h>
#include <stdio.h>






int
fn (int j, int len, int *ptr, int *dst)
{
  for (j = len; j > 0; j--)
    {
      *dst++ = ptr[0 * len];
      *dst++ = ptr[1 * len];
      *dst++ = ptr[2 * len];
      ptr++;
    }
}

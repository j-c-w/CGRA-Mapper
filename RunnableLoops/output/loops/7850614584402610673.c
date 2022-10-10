#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * dstPtr2, int length, const uint16_t * srcPtr2, int j,
    unsigned int shift)
{
  for (; j < length; j++)
    {
      dstPtr2[j] = ((srcPtr2[j]) >> shift);
    }
}

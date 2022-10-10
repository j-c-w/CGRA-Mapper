#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (uint8_t * dstPtr, int length, const uint16_t * srcPtr2, int j,
    unsigned int shift)
{
  for (; j < length; j++)
    {
      dstPtr[j] = ((srcPtr2[j]) >> shift);
    }
}

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (uint16_t * dst2, int i, uint16_t * dst1, const uint8_t * src)
{
  for (i = 0; i < 8; i++)
    {
      dst1[i] = dst2[i] = src[i] * 0x0101;
    }
}

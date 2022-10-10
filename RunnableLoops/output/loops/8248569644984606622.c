#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (uint8_t * dst, int16_t * src, int i, int stride)
{
  for (i = 0; i < 4; i++)
    {
      dst[0] += (unsigned) src[0];
      dst[1] += (unsigned) src[1];
      dst[2] += (unsigned) src[2];
      dst[3] += (unsigned) src[3];
      dst += stride;
      src += 4;
}}

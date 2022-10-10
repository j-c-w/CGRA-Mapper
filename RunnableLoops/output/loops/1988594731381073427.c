#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __int32_t int32_t;

int
fn (int32_t * src, uint16_t * dst, int i, int stride)
{
  for (i = 0; i < 8; i++)
    {
      dst[0] += (unsigned) src[0];
      dst[1] += (unsigned) src[1];
      dst[2] += (unsigned) src[2];
      dst[3] += (unsigned) src[3];
      dst[4] += (unsigned) src[4];
      dst[5] += (unsigned) src[5];
      dst[6] += (unsigned) src[6];
      dst[7] += (unsigned) src[7];
      dst += stride;
      src += 8;
}}

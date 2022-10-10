#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (unsigned int i, uint8_t * dst, int src_size, const uint8_t * src)
{
  for (i = 0; i < src_size; i += 3)
    {
      register uint8_t x;
      x = src[i + 2];
      dst[i + 1] = src[i + 1];
      dst[i + 2] = src[i + 0];
      dst[i + 0] = x;
}}

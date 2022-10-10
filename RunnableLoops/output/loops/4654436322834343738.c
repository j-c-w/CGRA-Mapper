#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * dst, int offset, int length)
{
  for (int j = 0; j < length; j++)
    {
      dst[j] = dst[j - offset];
}}

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int min_width, int i, int left, uint8_t * dst, const uint8_t * src)
{
  for (i = 0; i < min_width; i++)
    {
      const int temp = src[i];
      dst[i] = temp - left;
      left = temp;
}}

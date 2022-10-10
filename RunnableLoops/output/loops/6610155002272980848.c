#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (uint8_t value, const int stride, const uint8_t * pixel_ptr,
    uint16_t flags)
{
  int shift = 15;
  int y = 0;
  for (int x = 0; x < 4; x++)
    {
      flags |= (value == pixel_ptr[x + y * stride]) << shift;
      shift--;
}}

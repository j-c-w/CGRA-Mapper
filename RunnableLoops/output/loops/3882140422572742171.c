#include <stdint.h>
#include <stdio.h>




typedef __int8_t int8_t;

int
fn (const int out_stride, int8_t * out)
{
  for (int y = 0; y < 8; y++)
    {
      const int8_t l1 = out[-2], l0 = out[-1];
      const int8_t r0 = out[0], r1 = out[1];
      out[0] = (l0 + r0 * 2 + r1) >> 2;
      out[-1] = (r0 + l0 * 2 + l1) >> 2;
      out += out_stride;
}}

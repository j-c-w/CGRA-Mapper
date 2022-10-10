#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __uint16_t uint16_t;

int
fn (int64_t sum_v, const uint16_t * uptr, const uint16_t * vptr,
    int64_t sum_u, const int width)
{
  for (int x = 0; x < width; x++)
    {
      sum_u += uptr[x];
      sum_v += vptr[x];
}}

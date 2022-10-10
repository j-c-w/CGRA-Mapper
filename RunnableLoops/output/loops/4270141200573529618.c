#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * uptr, const int u, const int v, uint16_t * vptr,
    const int width)
{
  for (int x = 0; x < width; x++)
    {
      uptr[x] = u;
      vptr[x] = v;
}}

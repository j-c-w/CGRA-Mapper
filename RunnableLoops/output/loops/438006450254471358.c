#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * uptr, uint8_t * vptr, const int u, const int v, const int width)
{
  for (int x = 0; x < width; x++)
    {
      uptr[x] = u;
      vptr[x] = v;
}}

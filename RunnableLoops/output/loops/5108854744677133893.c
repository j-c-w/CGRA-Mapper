#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int width, uint16_t * uptr, const int half, uint16_t * vptr)
{
  for (int x = 0; x < width; x++)
    {
      uptr[x] = half;
      vptr[x] = half;
}}

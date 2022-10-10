#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int factor, const int mid, int x, uint8_t * udst, uint8_t * ydst,
    uint8_t * vdst, int w)
{
  for (x = 0; x < w; x++)
    {
      int c = factor * x / w;
      ydst[x] = c;
      udst[x] = mid;
      vdst[x] = mid;
}}

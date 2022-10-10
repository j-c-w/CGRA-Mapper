#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * vdst, const int mid, int x, uint16_t * udst, const int factor,
    int w, uint16_t * ydst)
{
  for (x = 0; x < w; x++)
    {
      int c = factor * x / w;
      ydst[x] = mid;
      udst[x] = mid;
      vdst[x] = c;
}}

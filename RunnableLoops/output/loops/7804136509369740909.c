#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int b, int i, uint8_t * src, uint8_t * dst, int g, int w, int r)
{
  for (i = 0; i < ((w) > (16) ? (16) : (w)); i++)
    {
      const int rt = src[i * 3 + 0];
      const int gt = src[i * 3 + 1];
      const int bt = src[i * 3 + 2];
      dst[i * 3 + 0] = rt - r;
      dst[i * 3 + 1] = gt - g;
      dst[i * 3 + 2] = bt - b;
      r = rt;
      g = gt;
      b = bt;
}}

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * buf, int color, int sy, int sx, int h, int w, int stride)
{
  for (int y = sy; y < sy + h; y++)
    {
      buf[sx] = color;
      buf[sx + w - 1] = color;
      buf += stride;
}}

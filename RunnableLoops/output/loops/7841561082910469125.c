#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * dst, int width, uint8_t * src, int src_linesize)
{
  for (int x = 0; x < width; x++)
    {
      dst[x] = (uint8_t) ((src[x] >> 1) + (src[x + src_linesize] >> 1));
}}

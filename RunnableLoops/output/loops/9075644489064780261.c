#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (uint32_t sum, int dst_linesize, uint32_t * dst, int w,
    const uint8_t * src)
{
  for (int x = 1; x < w; x++)
    {
      sum += src[x - 1];
      dst[x] = sum + dst[x - dst_linesize];
}}

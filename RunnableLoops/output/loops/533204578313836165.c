#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (const uint32_t * sq, uint8_t * pix, int s)
{
  int j = 0;
  for (j = 0; j < 16; j += 8)
    {
      register uint64_t x = *(uint64_t *) pix;
      s += sq[x & 0xff];
      s += sq[(x >> 8) & 0xff];
      s += sq[(x >> 16) & 0xff];
      s += sq[(x >> 24) & 0xff];
      s += sq[(x >> 32) & 0xff];
      s += sq[(x >> 40) & 0xff];
      s += sq[(x >> 48) & 0xff];
      s += sq[(x >> 56) & 0xff];
      pix += 8;
}}

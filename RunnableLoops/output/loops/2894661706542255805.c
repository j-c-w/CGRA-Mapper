#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * s, int idx, uint8_t * d)
{
  for (; idx < 15; idx += 4)
    {
      register unsigned v = *(const uint32_t *) &s[idx], g = v & 0xff00ff00;
      v &= 0xff00ff;
      *(uint32_t *) & d[idx] = (v >> 16) + g + (v << 16);
}}

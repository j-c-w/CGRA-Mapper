#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int x, const uint16_t * asrc, uint16_t * dst, const uint16_t * msrc,
    int shift, int w, int half)
{
  for (x = 0; x < w; x++)
    {
      dst[x] = ((msrc[x] * (((asrc[x] >> 1) & 1) + asrc[x])) + half) >> shift;
    }
}

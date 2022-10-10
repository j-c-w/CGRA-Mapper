#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * osrc, const uint8_t * bsrc, uint8_t * dst,
    const uint8_t * msrc, int w)
{
  for (int x = 0; x < w; x++)
    {
      const uint8_t invm = 255 - msrc[x];
      const uint16_t r =
	((uint16_t) (bsrc[x] * invm) +
	 (uint16_t) (msrc[x] * osrc[x] + 127)) / 255;
      dst[x] = r;
}}

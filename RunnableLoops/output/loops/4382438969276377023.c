#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int mmax, uint16_t * dst, const uint16_t * msrc, int hhalf,
    const uint16_t * bsrc, int w, const uint16_t * osrc)
{
  for (int x = 0; x < w; x++)
    {
      const uint16_t invm = mmax - msrc[x];
      const uint32_t r =
	((uint32_t) (bsrc[x] * invm) +
	 (uint32_t) (msrc[x] * osrc[x] + hhalf)) / mmax;
      dst[x] = r;
}}

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint64_t uint64_t;

int
fn (uint64_t * ldst, const uint8_t * uc, const uint8_t * vc, int i,
    const uint8_t * yc, const int chromWidth)
{
  for (i = 0; i < chromWidth; i += 2)
    {
      uint64_t k =
	yc[0] + (uc[0] << 8) + (yc[1] << 16) + ((unsigned) vc[0] << 24);
      uint64_t l =
	yc[2] + (uc[1] << 8) + (yc[3] << 16) + ((unsigned) vc[1] << 24);
      *ldst++ = k + (l << 32);
      yc += 4;
      uc += 2;
      vc += 2;
}}

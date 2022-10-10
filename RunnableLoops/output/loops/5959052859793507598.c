#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;
typedef __uint8_t uint8_t;

int
fn (uint64_t * ldst, const uint8_t * uc, const uint8_t * vc, int i,
    const uint8_t * yc, const int chromWidth)
{
  for (i = 0; i < chromWidth; i += 2)
    {
      uint64_t k =
	uc[0] + (yc[0] << 8) + (vc[0] << 16) + ((unsigned) yc[1] << 24);
      uint64_t l =
	uc[1] + (yc[2] << 8) + (vc[1] << 16) + ((unsigned) yc[3] << 24);
      *ldst++ = k + (l << 32);
      yc += 4;
      uc += 2;
      vc += 2;
}}

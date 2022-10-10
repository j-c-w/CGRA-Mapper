#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (int i, uint32_t * dst, const uint8_t * src)
{
  for (i = 0; i < 120; i += 4)
    {
      unsigned sample;
      sample =
	((unsigned) src[i + 0] << 25) | ((unsigned) src[i + 1] << 18) |
	((unsigned) src[i + 2] << 11) | ((unsigned) src[i + 3] << 4);
      dst[i / 4] = sample;
}}

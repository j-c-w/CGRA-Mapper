#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;
typedef __uint8_t uint8_t;

int
fn (uint64_t * sat, int x, const int width, uint64_t * square_sat,
    const uint8_t * src)
{
  for (x = 0; x < width; x++)
    {
      sat[x + 1] = sat[x] + src[x];
      square_sat[x + 1] = square_sat[x] + (uint64_t) src[x] * src[x];
    }
}

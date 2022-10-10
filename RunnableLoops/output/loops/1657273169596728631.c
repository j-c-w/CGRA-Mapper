#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * d, int width, int w, const uint8_t * s2, const uint8_t * s1)
{
  for (w = width; w >= 4; w -= 4)
    {
      d[0] = (s1[0] + s1[1] + s2[0] + s2[1] + 2) >> 2;
      d[1] = (s1[2] + s1[3] + s2[2] + s2[3] + 2) >> 2;
      d[2] = (s1[4] + s1[5] + s2[4] + s2[5] + 2) >> 2;
      d[3] = (s1[6] + s1[7] + s2[6] + s2[7] + 2) >> 2;
      s1 += 8;
      s2 += 8;
      d += 4;
    }
}

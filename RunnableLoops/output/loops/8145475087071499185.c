#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int skip, const uint8_t * p, int x1, int x, int x0, int sum[3])
{
  for (x = x0; x < x1; x += skip)
    {
      sum[0] += p[0];
      sum[1] += p[1];
      sum[2] += p[2];
      p += 3 * skip;
    }
}

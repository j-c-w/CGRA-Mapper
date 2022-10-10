#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int u, int x, int tpitch, int count, const uint8_t * dp)
{
  for (count = 0, u = x - 1; u < x + 2 && count < 2; u++)
    {
      count += dp[u - tpitch] > 3;
      count += dp[u] > 3;
      count += dp[u + tpitch] > 3;
    }
}

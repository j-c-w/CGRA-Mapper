#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __uint8_t uint8_t;

int
fn (int len, int i, int64_t * sum, int64_t * sum2, const uint8_t * src)
{
  for (i = 0; i < len; i++)
    {
      *sum += src[i];
      *sum2 += src[i] * src[i];
    }
}

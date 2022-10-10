#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;

int
fn (int x, int w, uint64_t * dst64)
{
  for (x = 0; x < w; x++)
    {
      dst64[x] = (dst64[x] << 3) & 0xFCFCFCFCFCFCFCFCULL;
    }
}

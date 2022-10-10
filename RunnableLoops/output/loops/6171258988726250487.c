#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (double *dst, int64_t index2, int64_t incr, int dst_index, int dst_size,
    const double *src)
{
  for (dst_index = 0; dst_index < dst_size; dst_index++)
    {
      dst[dst_index] = src[index2 >> 32];
      index2 += incr;
    }
}

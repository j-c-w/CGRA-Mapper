#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __uint16_t uint16_t;

int
fn (const int area, uint16_t * dst, int64_t * col_sum, const int size_w,
    const int width, int64_t sum)
{
  for (int x = 1; x < width; x++)
    {
      sum = sum - col_sum[x - size_w - 1] + col_sum[x + size_w];
      ((void) 0);
      dst[x] = ((sum) / (area));
}}

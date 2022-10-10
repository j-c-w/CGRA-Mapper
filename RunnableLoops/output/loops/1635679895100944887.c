#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int32_t int32_t;

int
fn (const int area, int32_t * col_sum, const int size_w, const int width,
    uint8_t * dst)
{
  int32_t sum = 0;
  for (int x = 1; x < width; x++)
    {
      sum = sum - col_sum[x - size_w - 1] + col_sum[x + size_w];
      ((void) 0);
      dst[x] = ((sum) / (area));
}}

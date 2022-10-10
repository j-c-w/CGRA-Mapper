#include <stdint.h>
#include <stdio.h>






int
fn (const int height, int row, int i, float temp, const int radius,
    const float *src, const int src_stride, const int width)
{
  int j = 0;
  for (int col = -radius; col <= radius; col++)
    {
      int x = i + row;
      int y = j + col;
      x = (x < 0) ? 0 : (x >= height ? height - 1 : x);
      y = (y < 0) ? 0 : (y >= width ? width - 1 : y);
      temp += src[x * src_stride + y];
}}

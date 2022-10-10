#include <stdint.h>
#include <stdio.h>






int
fn (const float b0, int y, const float q, const float c, float *dst,
    int width, const float b1, float g)
{
  for (int x = 0; x < width; x++)
    {
      (dst[(y) * width + (x)]) =
	b0 * (dst[(y) * width + (x)]) + b1 * (dst[(y + 1) * width + (x)]) + g;
      g = q * (dst[(y) * width + (x)]) + c * (dst[(y + 1) * width + (x)]);
}}

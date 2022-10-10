#include <stdint.h>
#include <stdio.h>






int
fn (const float b0, const float c, const float q, float *dst, int width,
    const float b1, float g)
{
  int y = 1;
  for (int x = 0; x < width; x++)
    {
      (dst[(y) * width + (x)]) =
	b0 * (dst[(y) * width + (x)]) + b1 * (dst[(y - 1) * width + (x)]) + g;
      g = q * (dst[(y) * width + (x)]) + c * (dst[(y - 1) * width + (x)]);
}}

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * dst, int j, int16_t * pred, int width, int16_t val)
{
  for (j = 1; j < width; j++)
    {
      val = pred[j] + dst[j];
      dst[j] = pred[j] = val;
      dst[j] += dst[j - 1];
    }
}

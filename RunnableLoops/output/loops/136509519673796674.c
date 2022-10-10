#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int8_t int8_t;

int
fn (int y, int x, int d, int j, int8_t pixel, uint8_t * dst, int linesize)
{
  int plane = 0;
  for (j = 0; j < d; j++)
    {
      dst[y * linesize + x * 4 + plane] = pixel;
      x++;
    }
}

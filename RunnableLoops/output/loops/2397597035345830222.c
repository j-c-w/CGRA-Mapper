#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int j, uint16_t * dst, uint16_t * last_line, unsigned int dst_width)
{
  for (j = 0; j < dst_width; ++j)
    {
      dst[j] = last_line[j];
    }
}

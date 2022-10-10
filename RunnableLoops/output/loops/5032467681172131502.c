#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int start, const uint8_t * color, int k, int end, int linesize,
    uint8_t * buf)
{
  for (k = start; k < end; k++)
    {
      buf[k * linesize + 0] = color[0];
      buf[k * linesize + 1] = color[1];
      buf[k * linesize + 2] = color[2];
      buf[k * linesize + 3] = color[3];
    }
}

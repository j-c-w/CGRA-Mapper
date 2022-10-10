#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (int v, const uint16_t * buf1, uint16_t * dc, uint16_t * buf, int x,
    int src_linesize, int width, int old, const uint8_t * src)
{
  for (x = 0; x < width; x++)
    {
      v =
	buf1[x] + src[2 * x] + src[2 * x + 1] + src[2 * x + src_linesize] +
	src[2 * x + 1 + src_linesize];
      old = buf[x];
      buf[x] = v;
      dc[x] = v - old;
    }
}

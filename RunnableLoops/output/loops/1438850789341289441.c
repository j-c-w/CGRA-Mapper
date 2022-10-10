#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int bs, int j, uint8_t * buf, int o)
{
  for (j = 0; j < bs; j++, i++, o++)
    {
      int x = (buf[i >> 1] >> (4 * (i & 1))) & 0xF, y =
	(buf[o >> 1] >> (4 * (o & 1))) & 0xF;
      buf[o >> 1] =
	(x << (4 * (o & 1))) | (buf[o >> 1] & (0xF << (4 * !(o & 1))));
      buf[i >> 1] =
	(y << (4 * (i & 1))) | (buf[i >> 1] & (0xF << (4 * !(i & 1))));
}}

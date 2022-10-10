#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * src, int i, int src_wrap)
{
  int tmp = 0;
  for (i = 0; i < 8; i++)
    {
      tmp +=
	src[0] + src[1] + src[2] + src[3] + src[4] + src[5] + src[6] + src[7];
      src += src_wrap;
    }
}

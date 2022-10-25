// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/texturedsp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t stride, int x, uint8_t * dst, int y)
{
  for (x = 0; x < 4; x++)
    {
      uint8_t *p = dst + x * 4 + y * stride;
      do
	{
	  uint8_t SWAP_tmp = p[1];
	  p[1] = p[0];
	  p[0] = SWAP_tmp;
	}
      while (0);
    }
}

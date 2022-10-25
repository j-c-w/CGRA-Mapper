// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mss2dsp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (uint8_t a, int w, int i, int h, ptrdiff_t plane_stride, uint8_t * plane,
    uint8_t * p, int j, uint8_t b)
{
  for (j = h - 1; j >= 0; j--)
    {
      p = plane + plane_stride * j;
      i = w - 1;
      p[i] = p[i >> 1];
      while ((i -= 2) > 0)
	{
	  a = p[i >> 1];
	  b = p[(i + 1) >> 1];
	  p[i] = (3 * a + b + 1) >> 2;
	  p[i + 1] = (a + 3 * b + 1) >> 2;
	}
    }
}

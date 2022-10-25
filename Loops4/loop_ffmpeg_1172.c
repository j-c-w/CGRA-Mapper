// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_negate.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int w, int components, int max, uint16_t * dst, int step,
    const uint16_t * src)
{
  for (int x = 0; x < w; x++)
    {
      switch (step)
	{
	case 4:
	  dst[3] = components & 8 ? max - src[3] : src[3];
	case 3:
	  dst[2] = components & 4 ? max - src[2] : src[2];
	case 2:
	  dst[1] = components & 2 ? max - src[1] : src[1];
	default:
	  dst[0] = components & 1 ? max - src[0] : src[0];
	}
      src += step;
      dst += step;
    }
}

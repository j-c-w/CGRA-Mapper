// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/hevcpred.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (int y, int fact, ptrdiff_t stride, int x, int idx, const uint16_t * ref,
    uint16_t * src, int size)
{
  for (x = 0; x < size; x += 4)
    {
      src[(x) + stride * (y)] =
	((32 - fact) * ref[x + idx + 1] + fact * ref[x + idx + 2] + 16) >> 5;
      src[(x + 1) + stride * (y)] =
	((32 - fact) * ref[x + 1 + idx + 1] + fact * ref[x + 1 + idx + 2] +
	 16) >> 5;
      src[(x + 2) + stride * (y)] =
	((32 - fact) * ref[x + 2 + idx + 1] + fact * ref[x + 2 + idx + 2] +
	 16) >> 5;
      src[(x + 3) + stride * (y)] =
	((32 - fact) * ref[x + 3 + idx + 1] + fact * ref[x + 3 + idx + 2] +
	 16) >> 5;
    }
}

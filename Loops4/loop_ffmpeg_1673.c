// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/hevcpred.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (int y, int fact, ptrdiff_t stride, int x, int idx, const uint16_t * ref,
    uint16_t * src, int size)
{
  for (y = 0; y < size; y++)
    {
      src[(x) + stride * (y)] =
	((32 - fact) * ref[y + idx + 1] + fact * ref[y + idx + 2] + 16) >> 5;
    }
}

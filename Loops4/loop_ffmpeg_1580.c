// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_transpose.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int w, int x, uint8_t * dst, ptrdiff_t src_linesize, uint8_t * src)
{
  for (x = 0; x < w; x++)
    {
      int64_t v =
	(((uint64_t) ((const uint8_t *) (src + x * src_linesize))[0] << 40) |
	 ((uint64_t) ((const uint8_t *) (src + x * src_linesize))[1] << 32) |
	 ((uint64_t) ((const uint8_t *) (src + x * src_linesize))[2] << 24) |
	 ((uint64_t) ((const uint8_t *) (src + x * src_linesize))[3] << 16) |
	 ((uint64_t) ((const uint8_t *) (src + x * src_linesize))[4] << 8) |
	 (uint64_t) ((const uint8_t *) (src + x * src_linesize))[5]);
      do
	{
	  uint64_t d = (v);
	  ((uint8_t *) (dst + 6 * x))[5] = (d);
	  ((uint8_t *) (dst + 6 * x))[4] = (d) >> 8;
	  ((uint8_t *) (dst + 6 * x))[3] = (d) >> 16;
	  ((uint8_t *) (dst + 6 * x))[2] = (d) >> 24;
	  ((uint8_t *) (dst + 6 * x))[1] = (d) >> 32;
	  ((uint8_t *) (dst + 6 * x))[0] = (d) >> 40;
	}
      while (0);
    }
}

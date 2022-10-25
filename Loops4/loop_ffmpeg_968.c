// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_hflip.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * in, int w, uint8_t * out)
{
  for (int j = 0; j < w; j++, out += 6, in -= 6)
    {
      int64_t v =
	(((uint64_t) ((const uint8_t *) (in))[0] << 40) |
	 ((uint64_t) ((const uint8_t *) (in))[1] << 32) |
	 ((uint64_t) ((const uint8_t *) (in))[2] << 24) |
	 ((uint64_t) ((const uint8_t *) (in))[3] << 16) |
	 ((uint64_t) ((const uint8_t *) (in))[4] << 8) |
	 (uint64_t) ((const uint8_t *) (in))[5]);
      do
	{
	  uint64_t d = (v);
	  ((uint8_t *) (out))[5] = (d);
	  ((uint8_t *) (out))[4] = (d) >> 8;
	  ((uint8_t *) (out))[3] = (d) >> 16;
	  ((uint8_t *) (out))[2] = (d) >> 24;
	  ((uint8_t *) (out))[1] = (d) >> 32;
	  ((uint8_t *) (out))[0] = (d) >> 40;
	}
      while (0);
    }
}

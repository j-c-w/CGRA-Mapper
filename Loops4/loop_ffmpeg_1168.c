// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_maskedmerge.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int hhalf, int w, int mmax, const uint16_t * msrc, const uint16_t * bsrc,
    const uint16_t * osrc, uint16_t * dst)
{
  for (int x = 0; x < w; x++)
    {
      const uint16_t invm = mmax - msrc[x];
      const uint32_t r =
	((uint32_t) (bsrc[x] * invm) +
	 (uint32_t) (msrc[x] * osrc[x] + hhalf)) / mmax;
      dst[x] = r;
}}

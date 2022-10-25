// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_maskedmerge.c

#include <stdint.h>
#include <stdio.h>






int
fn (const float *osrc, int w, const float *msrc, float *dst,
    const float *bsrc)
{
  for (int x = 0; x < w; x++)
    {
      const float invm = 1.f - msrc[x];
      const float r =
	((float) (bsrc[x] * invm) + (float) (msrc[x] * osrc[x] + 0.f)) + 0.f;
      dst[x] = r;
}}

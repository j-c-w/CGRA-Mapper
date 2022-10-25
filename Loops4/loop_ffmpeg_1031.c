// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_blend.c

#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;

int
fn (const float *bottom, float *dst, ptrdiff_t width, const float opacity,
    const float *top)
{
  for (int j = 0; j < width; j++)
    {
      dst[j] =
	top[j] +
	((((top[j] - bottom[j]) >=
	   0 ? (top[j] - bottom[j]) : (-(top[j] - bottom[j])))) -
	 top[j]) * opacity;
}}

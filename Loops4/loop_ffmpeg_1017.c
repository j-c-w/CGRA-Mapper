// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_blend.c

#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (const uint16_t * bottom, ptrdiff_t width, const float opacity,
    const uint16_t * top, uint16_t * dst)
{
  for (int j = 0; j < width; j++)
    {
      dst[j] =
	top[j] +
	(((((top[j]) == 0) ? (top[j]) : ((0) >
					 (((1 << 9) - 1) -
					  ((((1 << 9) - 1) -
					    (bottom[j])) << 9) /
					  (top[j])) ? (0) : (((1 << 9) - 1) -
							     ((((1 << 9) -
								1) -
							       (bottom[j])) <<
							      9) /
							     (top[j]))))) -
	 top[j]) * opacity;
}}

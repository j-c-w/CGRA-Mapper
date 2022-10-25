// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_blend.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t width, const float opacity, const uint8_t * top, uint8_t * dst,
    const uint8_t * bottom)
{
  for (int j = 0; j < width; j++)
    {
      dst[j] =
	top[j] +
	((((255 - top[j] - bottom[j]) >=
	   0 ? (255 - top[j] - bottom[j]) : (-(255 - top[j] - bottom[j])))) -
	 top[j]) * opacity;
}}

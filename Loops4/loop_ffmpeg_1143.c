// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_blend.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (const uint16_t * bottom, ptrdiff_t width, const float opacity,
    const uint16_t * top, uint16_t * dst)
{
  for (int j = 0; j < width; j++)
    {
      dst[j] = top[j] + ((((top[j]) & (bottom[j]))) - top[j]) * opacity;
}}

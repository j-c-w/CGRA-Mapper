// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_multiply.c

#include <stdint.h>
#include <stdio.h>






int
fn (int w, const float *src, const float *ref, float offset, float *dst,
    float scale)
{
  for (int x = 0; x < w; x++)
    {
      const float factor = (ref[x] + offset) * scale;
      dst[x] = src[x] * factor;
}}

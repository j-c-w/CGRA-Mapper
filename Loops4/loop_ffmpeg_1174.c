// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_dblur.c

#include <stdint.h>
#include <stdio.h>






int
fn (int y, const float q, int width, float *dst, const float b1,
    const float b0, float g, const float c)
{
  for (int x = 0; x < width; x++)
    {
      (dst[(y) * width + (x)]) =
	b0 * (dst[(y) * width + (x)]) + b1 * (dst[(y + 1) * width + (x)]) + g;
      g = q * (dst[(y) * width + (x)]) + c * (dst[(y + 1) * width + (x)]);
}}

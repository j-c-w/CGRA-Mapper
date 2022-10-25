// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/dsp/lossless.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (uint32_t * dst, const uint32_t * src, int num_pixels, int i)
{
  for (i = 0; i < num_pixels; ++i)
    {
      const uint32_t argb = src[i];
      const uint32_t green = ((argb >> 8) & 0xff);
      uint32_t red_blue = (argb & 0x00ff00ffu);
      red_blue += (green << 16) | green;
      red_blue &= 0x00ff00ffu;
      dst[i] = (argb & 0xff00ff00u) | red_blue;
}}

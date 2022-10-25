// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dvdsubdec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int g_add, int num_values, int y, int b_add, int i, int cr, uint8_t g,
    uint32_t * rgba, const uint8_t * ycbcr, const uint8_t * alpha,
    const uint8_t * cm, uint8_t b, uint8_t r, int r_add, int cb)
{
  for (i = num_values; i > 0; i--)
    {
      y = *ycbcr++;
      cr = *ycbcr++;
      cb = *ycbcr++;
      {
	cb = (cb) - 128;
	cr = (cr) - 128;
	r_add =
	  ((int) ((1.40200 * 255.0 / 224.0) * (1 << 10) + 0.5)) * cr +
	  (1 << (10 - 1));
	g_add =
	  -((int) ((0.34414 * 255.0 / 224.0) * (1 << 10) + 0.5)) * cb -
	  ((int) ((0.71414 * 255.0 / 224.0) * (1 << 10) + 0.5)) * cr +
	  (1 << (10 - 1));
	b_add =
	  ((int) ((1.77200 * 255.0 / 224.0) * (1 << 10) + 0.5)) * cb +
	  (1 << (10 - 1));
      };
      {
	y = ((y) - 16) * ((int) ((255.0 / 219.0) * (1 << 10) + 0.5));
	r = cm[(y + r_add) >> 10];
	g = cm[(y + g_add) >> 10];
	b = cm[(y + b_add) >> 10];
      };
      *rgba++ = ((unsigned) *alpha++ << 24) | (r << 16) | (g << 8) | b;
}}

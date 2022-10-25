// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/4xm.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint16_t uint16_t;

int
fn (int y, int x, int16_t (*block)[64], uint16_t * dst, int stride)
{
  for (x = 0; x < 8; x++)
    {
      int16_t *temp =
	block[(x >> 2) + 2 * (y >> 2)] + 2 * (x & 3) + 2 * 8 * (y & 3);
      int cb = block[4][x + 8 * y];
      int cr = block[5][x + 8 * y];
      int cg = (cb + cr) >> 1;
      int y;
      cb += cb;
      y = temp[0];
      dst[0] =
	((y + cb) >> 3) + (((y - cg) & 0xFC) << 3) + (((y + cr) & 0xF8) << 8);
      y = temp[1];
      dst[1] =
	((y + cb) >> 3) + (((y - cg) & 0xFC) << 3) + (((y + cr) & 0xF8) << 8);
      y = temp[8];
      dst[stride] =
	((y + cb) >> 3) + (((y - cg) & 0xFC) << 3) + (((y + cr) & 0xF8) << 8);
      y = temp[9];
      dst[1 + stride] =
	((y + cb) >> 3) + (((y - cg) & 0xFC) << 3) + (((y + cr) & 0xF8) << 8);
      dst += 2;
}}

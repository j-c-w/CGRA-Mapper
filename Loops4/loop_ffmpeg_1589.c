// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/alphablend.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int w, int x, uint8_t * d, int target_table[2][3], int plane,
    const uint8_t * a, const uint8_t * s)
{
  for (x = 0; x < w; x++)
    {
      unsigned u =
	s[x] * a[x] + target_table[((x ^ y) >> 5) & 1][plane] * (255 - a[x]) +
	128;
      d[x] = (257 * u) >> 16;
}}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/alphablend.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int plane_count, int x, uint8_t * d, int target_table[2][3],
    int plane, const uint8_t * a, const uint8_t * s)
{
  for (plane = 0; plane < plane_count; plane++)
    {
      int x_index = (plane_count + 1) * x;
      unsigned u =
	s[x_index + plane] * a[x_index] +
	target_table[((x ^ y) >> 5) & 1][plane] * (255 - a[x_index]) + 128;
      d[plane_count * x + plane] = (257 * u) >> 16;
}}

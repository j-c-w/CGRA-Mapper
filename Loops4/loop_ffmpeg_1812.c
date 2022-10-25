// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_huesaturation.c

#include <stdint.h>
#include <stdio.h>






int
fn (float (*a)[4], float temp[4][4], float (*b)[4])
{
  int y = 0;
  for (int x = 0; x < 4; x++)
    {
      temp[y][x] =
	b[y][0] * a[0][x] + b[y][1] * a[1][x] + b[y][2] * a[2][x] +
	b[y][3] * a[3][x];
}}

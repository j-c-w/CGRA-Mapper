// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/snow.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int w, uint8_t * (*halfpel)[4], int p, int x, int ls,
    uint8_t * src)
{
  for (x = 0; x < w; x++)
    {
      int i = y * ls + x;
      halfpel[3][p][i] =
	(20 * (src[i] + src[i + ls]) - 5 * (src[i - ls] + src[i + 2 * ls]) +
	 (src[i - 2 * ls] + src[i + 3 * ls]) + 16) >> 5;
}}

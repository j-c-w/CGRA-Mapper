// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/notchlc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int u[16][16], int v[16][16], uint16_t * dstv, uint16_t * dstu,
    int ulinesize, int vlinesize)
{
  int x = 0;
  int i = 0;
  for (int j = 0; j < 16; j++)
    {
      dstu[x + i * ulinesize + j] = u[i][j];
      dstv[x + i * vlinesize + j] = v[i][j];
}}

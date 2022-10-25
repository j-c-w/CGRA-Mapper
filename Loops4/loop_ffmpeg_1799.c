// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/roqvideoenc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int *stride, int i, int top, int *block, uint8_t * const *data,
    int u, int j, int left)
{
  int v = 0;
  for (j = 0; j < 2; j++)
    {
      int x = (top + i) * stride[0] + left + j;
      *block++ = data[0][x];
      x = (top + i) * stride[1] + left + j;
      u += data[1][x];
      v += data[2][x];
}}

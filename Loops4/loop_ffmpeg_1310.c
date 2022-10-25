// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mjpegdec.c

#include <stdint.h>
#include <stdio.h>






int
fn (int j, uint8_t * dst[4], int w)
{
  for (j = 0; j < w; j++)
    {
      int k = dst[3][j];
      int r = dst[0][j] * k;
      int g = dst[1][j] * k;
      int b = dst[2][j] * k;
      dst[0][j] = g * 257 >> 16;
      dst[1][j] = b * 257 >> 16;
      dst[2][j] = r * 257 >> 16;
      dst[3][j] = 255;
}}

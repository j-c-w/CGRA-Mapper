// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mobiclip.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int width, uint8_t * dst, uint8_t * src, int src_linesize)
{
  for (int x = 0; x < width; x++)
    {
      dst[x] = (uint8_t) ((src[x] >> 1) + (src[x + src_linesize] >> 1));
}}

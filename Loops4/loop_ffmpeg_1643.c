// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/jpeglsdec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, int w, int off, uint8_t * src)
{
  for (x = off; x < w; x += 3)
    {
      int g = src[x + 0] - ((src[x + 2] + src[x + 1]) >> 2) + 64;
      src[x + 0] = src[x + 2] + g + 128;
      src[x + 2] = src[x + 1] + g + 128;
      src[x + 1] = g;
}}

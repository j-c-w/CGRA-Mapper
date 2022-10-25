// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/sga.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int count, uint8_t * dst, int offset)
{
  int oi = 0;
  for (int j = 0; j < count * 2; j++)
    {
      dst[oi] = dst[oi - offset];
      oi++;
}}

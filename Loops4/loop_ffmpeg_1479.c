// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/exrenc.c

#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (uint8_t * src, ptrdiff_t size, int p)
{
  for (ptrdiff_t i = 1; i < size; i++)
    {
      int d = src[i] - p + 384;
      p = src[i];
      src[i] = d;
}}

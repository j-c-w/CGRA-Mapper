// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_monochrome.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * uptr, const int half, const int width, uint16_t * vptr)
{
  for (int x = 0; x < width; x++)
    {
      uptr[x] = half;
      vptr[x] = half;
}}

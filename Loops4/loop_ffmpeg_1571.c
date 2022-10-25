// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vsrc_testsrc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int w, const int mid, int x, uint16_t * ydst, const int factor,
    uint16_t * vdst, uint16_t * udst)
{
  for (x = 0; x < w; x++)
    {
      int c = factor * x / w;
      ydst[x] = c;
      udst[x] = mid;
      vdst[x] = mid;
}}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_colorize.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int v, uint16_t * vptr, uint16_t * uptr, const int u,
    const int width)
{
  for (int x = 0; x < width; x++)
    {
      uptr[x] = u;
      vptr[x] = v;
}}

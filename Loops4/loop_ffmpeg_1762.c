// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_colorcorrect.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int min_u, const uint8_t * uptr, const int width, const uint8_t * vptr,
    int max_u)
{
  int max_v = 0;
  int min_v = 255;
  for (int x = 0; x < width; x++)
    {
      min_u = ((min_u) > (uptr[x]) ? (uptr[x]) : (min_u));
      min_v = ((min_v) > (vptr[x]) ? (vptr[x]) : (min_v));
      max_u = ((max_u) > (uptr[x]) ? (max_u) : (uptr[x]));
      max_v = ((max_v) > (vptr[x]) ? (max_v) : (vptr[x]));
}}

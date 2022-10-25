// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_shufflepixels.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * map, int height)
{
  int y = 0;
  for (int i = 1; i < height; i++)
    {
      map[y + i] = map[y] + i;
}}

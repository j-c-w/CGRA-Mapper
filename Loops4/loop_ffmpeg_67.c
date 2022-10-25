// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_bm3d.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int x, const int block_size, const uint16_t * srcp, const uint16_t * refp)
{
  double dist = 0.;
  for (x = 0; x < block_size; x++)
    {
      double temp = refp[x] - srcp[x];
      dist += temp * temp;
}}

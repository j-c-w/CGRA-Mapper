// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_neighbor.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, int i, const uint8_t ** coordinates)
{
  int sum = 0;
  for (i = 0; i < 8; sum += *(coordinates[i++] + x));
}

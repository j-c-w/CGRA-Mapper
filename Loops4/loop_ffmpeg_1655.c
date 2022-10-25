// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_photosensitivity.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int sum[3], int x, int x0, int skip, int x1, const uint8_t * p)
{
  for (x = x0; x < x1; x += skip)
    {
      sum[0] += p[0];
      sum[1] += p[1];
      sum[2] += p[2];
      p += 3 * skip;
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavutil/imgutils.c

#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;

int
fn (int i, int *dst_linesizes, ptrdiff_t src_linesizes1[4],
    const int *src_linesizes, ptrdiff_t dst_linesizes1[4])
{
  for (i = 0; i < 4; i++)
    {
      dst_linesizes1[i] = dst_linesizes[i];
      src_linesizes1[i] = src_linesizes[i];
    }
}

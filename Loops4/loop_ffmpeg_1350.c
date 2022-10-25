// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_ciescope.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * const pixels, const int leftEdge, const int linesize,
    const int row, const int w, int j)
{
  for (j = w - 1; j >= leftEdge && pixels[row * linesize + j * 4 + 0] == 0;
       j--);
}

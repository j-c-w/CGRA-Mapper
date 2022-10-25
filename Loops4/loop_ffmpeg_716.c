// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_ciescope.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * const pixels, int i, const int row, const int linesize,
    const int w)
{
  for (i = 0; i < w && pixels[row * linesize + i * 4 + 0] == 0; i++);
}

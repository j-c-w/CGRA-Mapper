// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/avf_showcqt.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, uint8_t g, int x, int linesize, uint8_t r, uint8_t b, int height,
    uint8_t * data)
{
  for (y = 0; y < height; y++)
    {
      data[linesize * y + 4 * x] = r;
      data[linesize * y + 4 * x + 1] = g;
      data[linesize * y + 4 * x + 2] = b;
    }
}

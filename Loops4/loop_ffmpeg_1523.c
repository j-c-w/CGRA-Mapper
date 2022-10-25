// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/a64multienc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, uint8_t * buf, int x, int *charmap, int b_width)
{
  for (x = 0; x < b_width; x++)
    {
      buf[y * b_width + x] = charmap[y * b_width + x];
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vsrc_testsrc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (unsigned int i, unsigned int r, uint8_t alpha[256])
{
  for (i = 0; i < 256; i++)
    {
      r = r * 1664525 + 1013904223;
      alpha[i] = r >> 24;
    }
}

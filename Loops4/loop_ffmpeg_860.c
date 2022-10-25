// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/pcx.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (unsigned int bytes_per_line, int i, unsigned int x, int v,
    uint8_t * scanline, unsigned int nplanes, int m)
{
  for (i = nplanes - 1; i >= 0; i--)
    {
      v <<= 1;
      v += !!(scanline[i * bytes_per_line + (x >> 3)] & m);
    }
}

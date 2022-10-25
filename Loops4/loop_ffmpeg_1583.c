// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/pcx.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * ptr, uint8_t * scanline, unsigned int w,
    unsigned int bytes_per_line, unsigned int x)
{
  for (x = 0; x < w; x++)
    {
      ptr[3 * x] = scanline[x];
      ptr[3 * x + 1] = scanline[x + bytes_per_line];
      ptr[3 * x + 2] = scanline[x + (bytes_per_line << 1)];
    }
}

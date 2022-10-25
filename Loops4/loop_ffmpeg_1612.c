// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/swscale_unscaled.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int width, uint16_t * src_line, int x, uint16_t ** dst, int shift)
{
  for (x = 0; x < width; x++)
    {
      dst[0][x] = *src_line++ >> shift;
      dst[1][x] = *src_line++ >> shift;
      dst[2][x] = *src_line++ >> shift;
      dst[3][x] = 0xFFFF;
    }
}

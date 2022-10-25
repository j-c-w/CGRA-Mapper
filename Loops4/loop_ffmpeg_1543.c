// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/videodsp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int x, int start_x, uint16_t * bufp)
{
  for (x = 0; x < start_x; x++)
    {
      bufp[x] = bufp[start_x];
    }
}

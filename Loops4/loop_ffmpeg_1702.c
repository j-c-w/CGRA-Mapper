// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/h264pred.c

#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (ptrdiff_t stride, int i, uint16_t * src)
{
  int dc = 0;
  for (i = 0; i < 16; i++)
    {
      dc += src[i - stride];
    }
}

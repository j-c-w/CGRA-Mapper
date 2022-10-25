// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/msmpeg4.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int x, int block_size, uint8_t * src, int stride)
{
  int sum = 0;
  for (x = 0; x < block_size; x++)
    {
      sum += src[x + y * stride];
    }
}

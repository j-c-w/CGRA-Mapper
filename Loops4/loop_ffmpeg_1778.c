// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/vp6.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, uint8_t * src, int sum)
{
  int square_sum = 0;
  for (x = 0; x < 8; x += 2)
    {
      sum += src[x];
      square_sum += src[x] * src[x];
    }
}

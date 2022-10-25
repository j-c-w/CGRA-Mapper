// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/h261.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, int temp[64], uint8_t * src, int stride)
{
  for (x = 0; x < 8; x++)
    {
      temp[x] = 4 * src[x];
      temp[x + 7 * 8] = 4 * src[x + 7 * stride];
    }
}

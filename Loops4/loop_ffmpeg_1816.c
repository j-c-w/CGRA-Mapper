// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/speedhq.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t block[128], int x, uint8_t * last_alpha)
{
  int y = 0;
  for (x = 0; x < 16; x++)
    {
      last_alpha[x] -= block[y * 16 + x];
    }
}

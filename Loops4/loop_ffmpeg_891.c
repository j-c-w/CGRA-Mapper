// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/pngdec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, uint8_t * pd)
{
  for (i--; i >= 0; i--)
    {
      pd[2 * i + 1] = pd[i] & 15;
      pd[2 * i + 0] = pd[i] >> 4;
    }
}

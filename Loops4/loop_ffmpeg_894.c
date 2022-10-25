// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/pngdec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, uint8_t * pd)
{
  for (i--; i >= 0; i--)
    {
      pd[8 * i + 7] = pd[i] & 1;
      pd[8 * i + 6] = (pd[i] >> 1) & 1;
      pd[8 * i + 5] = (pd[i] >> 2) & 1;
      pd[8 * i + 4] = (pd[i] >> 3) & 1;
      pd[8 * i + 3] = (pd[i] >> 4) & 1;
      pd[8 * i + 2] = (pd[i] >> 5) & 1;
      pd[8 * i + 1] = (pd[i] >> 6) & 1;
      pd[8 * i + 0] = pd[i] >> 7;
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dvbsubdec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int x, uint8_t list[256], int (*counttab2)[256])
{
  int scorev = 0;
  for (y = 0; y < 256; y++)
    {
      scorev += list[y] * counttab2[y + 1][x];
    }
}

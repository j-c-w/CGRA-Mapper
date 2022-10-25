// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/lagarith.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * buf, const int HEAD, int i, int L)
{
  for (i = 0; i < HEAD; i++)
    {
      L += buf[i];
      buf[i] = L;
    }
}

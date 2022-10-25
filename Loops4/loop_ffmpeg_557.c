// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/vc1_mc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * srcU, uint8_t * srcV, int k, int i)
{
  for (i = 0; i < k; i++)
    {
      srcU[i] = ((srcU[i] - 128) >> 1) + 128;
      srcV[i] = ((srcV[i] - 128) >> 1) + 128;
    }
}

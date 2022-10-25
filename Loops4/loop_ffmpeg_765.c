// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/utvideoenc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, uint8_t ** dst, const uint8_t * sa, int width, const uint8_t * sb,
    const uint8_t * sr, int k, const uint8_t * sg, unsigned int g)
{
  for (i = 0; i < width; i++)
    {
      g = sg[i];
      dst[0][k] = g;
      g += 0x80;
      dst[1][k] = sb[i] - g;
      dst[2][k] = sr[i] - g;
      dst[3][k] = sa[i];
      k++;
    }
}

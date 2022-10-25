// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/scpr.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;

int
fn (uint16_t cnts[256], uint32_t a, uint16_t freqs[512], int b)
{
  for (b = a = 0; b < 256; b++)
    {
      freqs[2 * b] = cnts[b];
      freqs[2 * b + 1] = a;
      a += cnts[b];
    }
}

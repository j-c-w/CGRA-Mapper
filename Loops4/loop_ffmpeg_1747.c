// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mpegvideoencdsp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (int s, const uint32_t * sq, uint8_t * pix)
{
  int j = 0;
  for (j = 0; j < 16; j += 8)
    {
      register uint64_t x = *(uint64_t *) pix;
      s += sq[x & 0xff];
      s += sq[(x >> 8) & 0xff];
      s += sq[(x >> 16) & 0xff];
      s += sq[(x >> 24) & 0xff];
      s += sq[(x >> 32) & 0xff];
      s += sq[(x >> 40) & 0xff];
      s += sq[(x >> 48) & 0xff];
      s += sq[(x >> 56) & 0xff];
      pix += 8;
}}

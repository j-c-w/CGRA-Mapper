// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/zmbvenc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (int i, int bw_bytes, uint8_t * src2, uint16_t histogram[256],
    uint8_t * src)
{
  for (i = 0; i < bw_bytes; i++)
    {
      int t = src[i] ^ src2[i];
      histogram[t]++;
}}

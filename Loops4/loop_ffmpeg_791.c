// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mpegvideo_enc.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int last, uint8_t * permutation, int i, int16_t temp[64], int16_t * block,
    const uint8_t * scantable)
{
  for (i = 0; i <= last; i++)
    {
      const int j = scantable[i];
      const int perm_j = permutation[j];
      block[perm_j] = temp[j];
}}

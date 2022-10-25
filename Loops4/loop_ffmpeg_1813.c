// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/h274.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int8_t int8_t;

int
fn (int8_t (*out)[64], const uint8_t deblock_coeff)
{
  int y = 0;
  for (int x = 0; x < 64; x++)
    {
      out[y + 0][x] = (out[y + 0][x] * deblock_coeff) >> 7;
      out[y + 7][x] = (out[y + 7][x] * deblock_coeff) >> 7;
}}

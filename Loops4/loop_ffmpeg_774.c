// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/input.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;
typedef __int16_t int16_t;
typedef __uint16_t uint16_t;

int
fn (int16_t * dstV, int i, int width, uint32_t * pal, uint16_t * dstU,
    const uint8_t * src1)
{
  for (i = 0; i < width; i++)
    {
      int p = pal[src1[i]];
      dstU[i] = (uint8_t) (p >> 8) << 6;
      dstV[i] = (uint8_t) (p >> 16) << 6;
}}

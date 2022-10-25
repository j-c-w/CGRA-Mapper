// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/input.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int i, int16_t * dst, int width, uint32_t * pal, const uint8_t * src)
{
  for (i = 0; i < width; i++)
    {
      int d = src[i];
      dst[i] = (pal[d] & 0xFF) << 6;
}}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/input.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (int32_t gy, int32_t by, int i, const uint8_t ** src, int width,
    int32_t ry, uint16_t * dst)
{
  for (i = 0; i < width; i++)
    {
      int g = src[0][i];
      int b = src[1][i];
      int r = src[2][i];
      dst[i] = (ry * r + gy * g + by * b + (0x801 << (15 - 7))) >> (15 - 6);
}}

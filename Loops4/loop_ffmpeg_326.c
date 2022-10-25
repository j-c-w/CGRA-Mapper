// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/h264idct.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint8_t uint8_t;

int
fn (const uint8_t x_offset[2], int i, unsigned int temp[8], int qmul,
    int32_t * block, const int stride)
{
  for (i = 0; i < 2; i++)
    {
      const int offset = x_offset[i];
      const unsigned z0 = temp[2 * 0 + i] + temp[2 * 2 + i];
      const unsigned z1 = temp[2 * 0 + i] - temp[2 * 2 + i];
      const unsigned z2 = temp[2 * 1 + i] - temp[2 * 3 + i];
      const unsigned z3 = temp[2 * 1 + i] + temp[2 * 3 + i];
      block[stride * 0 + offset] = (int) ((z0 + z3) * qmul + 128) >> 8;
      block[stride * 1 + offset] = (int) ((z1 + z2) * qmul + 128) >> 8;
      block[stride * 2 + offset] = (int) ((z1 - z2) * qmul + 128) >> 8;
      block[stride * 3 + offset] = (int) ((z0 - z3) * qmul + 128) >> 8;
}}

// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/dsp/ssim.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (uint32_t sse2, int i, const uint8_t * src2, int len, const uint8_t * src1)
{
  for (i = 0; i < len; ++i)
    {
      const int32_t diff = src1[i] - src2[i];
      sse2 += diff * diff;
}}

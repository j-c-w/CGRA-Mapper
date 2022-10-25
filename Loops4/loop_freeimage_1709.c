// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/dsp/ssim_sse2.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (const uint8_t * src2, uint32_t sse2, const uint8_t * src1, int len)
{
  int i = 0;
  for (; i < len; ++i)
    {
      const int32_t diff = src1[i] - src2[i];
      sse2 += diff * diff;
}}

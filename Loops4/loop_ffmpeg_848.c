// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/x86/hscale_fast_bilinear_simd.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int i, int16_t * dst1, const uint8_t * src2, int dstWidth, int16_t * dst2,
    int srcW, int xInc, const uint8_t * src1)
{
  for (i = dstWidth - 1; (i * xInc) >> 16 >= srcW - 1; i--)
    {
      dst1[i] = src1[srcW - 1] * 128;
      dst2[i] = src2[srcW - 1] * 128;
    }
}

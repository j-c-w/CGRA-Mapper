// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavutil/tx_int32.c

#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef int32_t TXSample;

int
fn (TXSample * dst, int len2, ptrdiff_t stride, int len4, int len)
{
  for (int i = 0; i < len4; i++)
    {
      dst[i * stride] = -dst[(len2 - i - 1) * stride];
      dst[(len - i - 1) * stride] = dst[(len2 + i + 0) * stride];
}}

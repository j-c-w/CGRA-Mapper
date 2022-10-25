// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/dsp/yuv.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, const int16_t * ref, int16_t * dst, const int16_t * src, int len)
{
  for (i = 0; i < len; ++i)
    {
      const int diff_uv = ref[i] - src[i];
      dst[i] += diff_uv;
}}

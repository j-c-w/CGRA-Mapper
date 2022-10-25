// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/utils.c

#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __int32_t int32_t;

int
fn (int i, int32_t ** filterPos, int64_t * filter, int filterSize,
    const int64_t fone, int64_t xDstInSrc, int xInc, int dstW)
{
  for (i = 0; i < dstW; i++)
    {
      int xx = (xDstInSrc - ((filterSize - 1) << 15) + (1 << 15)) >> 16;
      (*filterPos)[i] = xx;
      filter[i] = fone;
      xDstInSrc += xInc;
}}

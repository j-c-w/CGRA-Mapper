// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/utils.c

#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __int32_t int32_t;

int
fn (int i, int32_t ** filterPos, int64_t * filter, int filterSize, int j)
{
  for (j = 1; j < filterSize; j++)
    {
      int left = ((j + (*filterPos)[i]) > (0) ? (j + (*filterPos)[i]) : (0));
      filter[i * filterSize + left] += filter[i * filterSize + j];
      filter[i * filterSize + j] = 0;
}}

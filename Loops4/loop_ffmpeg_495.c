// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/bink.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __int32_t int32_t;
typedef __uint8_t uint8_t;

int
fn (int *coef_idx, int i, int32_t * block, const uint32_t * quant,
    int coef_count, const uint8_t * scan)
{
  for (i = 0; i < coef_count; i++)
    {
      int idx = coef_idx[i];
      block[scan[idx]] = (int) (block[scan[idx]] * quant[idx]) >> 11;
}}

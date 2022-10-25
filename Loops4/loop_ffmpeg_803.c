// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/lsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int lp_half_order, int i, int16_t * lp, int f2[11], int f1[11])
{
  for (i = 1; i < lp_half_order + 1; i++)
    {
      int ff1 = f1[i] + f1[i - 1];
      int ff2 = f2[i] - f2[i - 1];
      ff1 += 1 << 10;
      lp[i] = (ff1 + ff2) >> 11;
      lp[(lp_half_order << 1) + 1 - i] = (ff1 - ff2) >> 11;
}}

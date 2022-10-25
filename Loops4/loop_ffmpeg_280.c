// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/g723_1.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int temp, int i, const int16_t dc_lsp[10], int16_t * prev_lsp, int pred,
    int16_t * cur_lsp)
{
  for (i = 0; i < 10; i++)
    {
      temp = ((prev_lsp[i] - dc_lsp[i]) * pred + (1 << 14)) >> 15;
      cur_lsp[i] += dc_lsp[i] + temp;
    }
}

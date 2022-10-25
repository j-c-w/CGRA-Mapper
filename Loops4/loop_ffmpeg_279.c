// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/g723_1enc.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * prev_lsp, const int16_t dc_lsp[10], int16_t * lsp, int i)
{
  for (i = 0; i < 10; i++)
    {
      lsp[i] -=
	dc_lsp[i] + (((prev_lsp[i] - dc_lsp[i]) * 12288 + (1 << 14)) >> 15);
    }
}

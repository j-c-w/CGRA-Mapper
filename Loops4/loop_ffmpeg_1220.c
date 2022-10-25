// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/g723_1enc.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int16_t temp[4], int16_t weight[10], int j,
    const int16_t ff_g723_1_lsp_band2[256][4])
{
  for (j = 0; j < 4; j++)
    {
      temp[j] =
	(weight[j + (6)] * ff_g723_1_lsp_band2[i][j] + (1 << 14)) >> 15;
    }
}

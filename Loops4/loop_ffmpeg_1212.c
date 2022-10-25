// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/g723_1enc.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int16_t temp[4], int16_t weight[10],
    const int16_t ff_g723_1_lsp_band0[256][3], int j)
{
  for (j = 0; j < 3; j++)
    {
      temp[j] =
	(weight[j + (0)] * ff_g723_1_lsp_band0[i][j] + (1 << 14)) >> 15;
    }
}

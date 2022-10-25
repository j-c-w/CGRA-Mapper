// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/g729dec.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t vq_2nd_low, int16_t * quantizer_output,
    const int16_t cb_lsp_1st[128][10], int i, int16_t vq_2nd_high,
    const int16_t cb_lsp_2nd[32][10], int16_t vq_1st)
{
  for (i = 0; i < 5; i++)
    {
      quantizer_output[i] = cb_lsp_1st[vq_1st][i] + cb_lsp_2nd[vq_2nd_low][i];
      quantizer_output[i + 5] =
	cb_lsp_1st[vq_1st][i + 5] + cb_lsp_2nd[vq_2nd_high][i + 5];
    }
}

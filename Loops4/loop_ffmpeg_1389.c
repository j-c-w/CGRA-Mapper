// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/opus_silk.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int32_t lsp[16], const int16_t ff_silk_cosine[],
    const uint8_t ff_silk_lsf_ordering_nbmb[],
    const uint8_t ff_silk_lsf_ordering_wb[], int k, const int16_t * nlsf,
    int order)
{
  for (k = 0; k < order; k++)
    {
      int index = nlsf[k] >> 8;
      int offset = nlsf[k] & 255;
      int k2 =
	(order ==
	 10) ? ff_silk_lsf_ordering_nbmb[k] : ff_silk_lsf_ordering_wb[k];
      lsp[k2] = ff_silk_cosine[index] * 256;
      lsp[k2] += (ff_silk_cosine[index + 1] - ff_silk_cosine[index]) * offset;
      lsp[k2] = (lsp[k2] + 4) >> 3;
}}

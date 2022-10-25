// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ilbcdec.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (int16_t * lsp, int i, int16_t * lsf, const int16_t cos_derivative_tbl[64],
    int k, int16_t freq, int32_t tmp, const int16_t cos_tbl[64], int order,
    int16_t diff)
{
  for (i = 0; i < order; i++)
    {
      freq = (lsf[i] * 20861) >> 15;
      k = ((freq >> 8) > (63) ? (63) : (freq >> 8));
      diff = freq & 0xFF;
      tmp = cos_derivative_tbl[k] * diff;
      lsp[i] = cos_tbl[k] + (tmp >> 12);
    }
}

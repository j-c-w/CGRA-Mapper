// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ilbcdec.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (const uint8_t lsf_dim_codebook[3], int i, int16_t * lsfdeq,
    const int16_t lsf_codebook[1088], int16_t * index, int pos, int j)
{
  int cb_pos = 0;
  for (j = 0; j < lsf_dim_codebook[i]; j++)
    {
      lsfdeq[pos + j] =
	lsf_codebook[cb_pos + index[i] * lsf_dim_codebook[i] + j];
    }
}

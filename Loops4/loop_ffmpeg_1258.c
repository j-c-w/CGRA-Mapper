// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/nellymoserdec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (float *pptr, float pval, int i, float val,
    const uint8_t ff_nelly_band_sizes_table[23], float *bptr, int j)
{
  for (j = 0; j < ff_nelly_band_sizes_table[i]; j++)
    {
      *bptr++ = val;
      *pptr++ = pval;
    }
}

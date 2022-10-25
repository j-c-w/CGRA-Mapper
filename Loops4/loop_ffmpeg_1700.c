// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/aacenc_tns.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int *quants, const uint8_t aac_cb_range[12], const int dim, int off,
    int cb, int j)
{
  int curidx = 0;
  for (j = 0; j < dim; j++)
    {
      curidx *= aac_cb_range[cb];
      curidx += quants[j] + off;
    }
}

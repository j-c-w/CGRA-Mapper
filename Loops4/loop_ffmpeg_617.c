// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/lsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int lsfq_min_distance, int lsfq_min, int16_t * lsfq, int lp_order)
{
  for (i = 0; i < lp_order; i++)
    {
      lsfq[i] = ((lsfq[i]) > (lsfq_min) ? (lsfq[i]) : (lsfq_min));
      lsfq_min = lsfq[i] + lsfq_min_distance;
    }
}

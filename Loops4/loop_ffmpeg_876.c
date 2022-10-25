// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/g729postfilter.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int gt, int fact, int i, int16_t * res_pst, int sh_fact, int ga,
    int subframe_size, int16_t * out, int tmp2)
{
  for (i = subframe_size - 1; i >= 1; i--)
    {
      tmp2 = (gt * res_pst[i - 1]) * 2 + 0x4000;
      tmp2 = res_pst[i] + (tmp2 >> 15);
      tmp2 = (tmp2 * ga + fact) >> sh_fact;
      out[i] = tmp2;
    }
}

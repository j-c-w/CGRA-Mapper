// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/g729dec.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int gain_code, const int16_t * in, int subframe_size,
    int16_t fc_new[40], int16_t * out, const int16_t * fc_cur)
{
  for (i = 0; i < subframe_size; i++)
    {
      out[i] = in[i];
      out[i] -= (gain_code * fc_cur[i] + 0x2000) >> 14;
      out[i] += (gain_code * fc_new[i] + 0x2000) >> 14;
    }
}

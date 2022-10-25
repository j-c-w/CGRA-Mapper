// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/opus_silk.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t q[9], int32_t lpc32[16], int k, int32_t p[9], int order)
{
  for (k = 0; k < order >> 1; k++)
    {
      int32_t p_tmp = p[k + 1] + p[k];
      int32_t q_tmp = q[k + 1] - q[k];
      lpc32[k] = -q_tmp - p_tmp;
      lpc32[order - k - 1] = q_tmp - p_tmp;
    }
}

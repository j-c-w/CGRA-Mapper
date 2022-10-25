// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/amrwbdec.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const int16_t isf_mean[16], int i, float tmp, float *isf_q,
    float *isf_past)
{
  for (i = 0; i < 16; i++)
    {
      tmp = isf_q[i];
      isf_q[i] += isf_mean[i] * (1.0f / (1 << 15));
      isf_q[i] += (1.0 / 3.0) * isf_past[i];
      isf_past[i] = tmp;
    }
}

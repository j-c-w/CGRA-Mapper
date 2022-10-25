// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/amrnbdec.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, float lpc_d[10], const float *gamma_n, const float *gamma_d,
    float lpc_n[10], float *lpc)
{
  for (i = 0; i < 10; i++)
    {
      lpc_n[i] = lpc[i] * gamma_n[i];
      lpc_d[i] = lpc[i] * gamma_d[i];
    }
}

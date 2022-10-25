// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/speexdec.c

#include <stdint.h>
#include <stdio.h>






int
fn (float gamma, float tmp, float *lpc_out, const float *lpc_in, int order)
{
  for (int i = 0; i < order; i++)
    {
      lpc_out[i] = tmp * lpc_in[i];
      tmp *= gamma;
}}

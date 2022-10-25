// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/opus_silk.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int16_t int16_t;

int
fn (const int16_t * lpc, int order, int k, int32_t * row)
{
  int DC_resp = 0;
  for (k = 0; k < order; k++)
    {
      DC_resp += lpc[k];
      row[k] = lpc[k] * 4096;
    }
}

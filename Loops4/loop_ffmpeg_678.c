// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/lpc.c

#include <stdint.h>
#include <stdio.h>






int
fn (double scale, int i, double *lpc_in, int order)
{
  for (i = 0; i < order; i++)
    {
      lpc_in[i] *= scale;
    }
}

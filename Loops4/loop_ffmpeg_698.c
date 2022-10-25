// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/amrwbdec.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, float gamma, float *out, float fac, int size, const float *lpc)
{
  for (i = 0; i < size; i++)
    {
      out[i] = lpc[i] * fac;
      fac *= gamma;
    }
}

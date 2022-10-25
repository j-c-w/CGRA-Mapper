// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/atrac.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *p3, float *inlo, float *inhi, unsigned int nIn)
{
  for (i = 0; i < nIn; i += 2)
    {
      p3[2 * i + 0] = inlo[i] + inhi[i];
      p3[2 * i + 1] = inlo[i] - inhi[i];
      p3[2 * i + 2] = inlo[i + 1] + inhi[i + 1];
      p3[2 * i + 3] = inlo[i + 1] - inhi[i + 1];
    }
}

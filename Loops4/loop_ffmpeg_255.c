// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/evrcdec.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *in, float scratch[54], float sum2, int length, float sum1)
{
  for (i = 0, sum1 = 0, sum2 = 0; i < length; i++)
    {
      sum1 += in[i] * in[i];
      sum2 += scratch[i] * scratch[i];
    }
}

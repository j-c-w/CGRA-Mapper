// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ra288.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *out, float buffer2[37], float *out2, float buffer1[37],
    int order)
{
  for (i = 0; i <= order; i++)
    {
      out2[i] = out2[i] * 0.5625 + buffer1[i];
      out[i] = out2[i] + buffer2[i];
    }
}

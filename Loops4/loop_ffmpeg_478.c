// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/opus_pvq.c

#include <stdint.h>
#include <stdio.h>






int
fn (float e[2], int i, const float *X, const float *Y, int N)
{
  for (i = 0; i < N; i++)
    {
      e[0] += X[i] * X[i];
      e[1] += Y[i] * Y[i];
    }
}

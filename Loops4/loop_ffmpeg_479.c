// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/opus_pvq.c

#include <stdint.h>
#include <stdio.h>






int
fn (float *X, int i, float xp, float side, int N, float *Y)
{
  for (i = 0; i < N; i++)
    {
      xp += X[i] * Y[i];
      side += Y[i] * Y[i];
    }
}

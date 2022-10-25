// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/truemotion2.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, int *data, int *deltas, int *last, int j, unsigned int *CD)
{
  for (i = 0; i < 2; i++)
    {
      CD[j] += deltas[i + j * 2];
      last[i] += CD[j];
      data[i] = last[i];
    }
}

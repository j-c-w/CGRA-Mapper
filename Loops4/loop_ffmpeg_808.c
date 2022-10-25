// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dct.c

#include <stdint.h>
#include <stdio.h>




typedef float FFTSample;

int
fn (int n, int i, FFTSample * data)
{
  for (i = 1; i < n - 2; i += 2)
    {
      data[i + 1] += data[i - 1];
      data[i] = -data[i + 2];
    }
}

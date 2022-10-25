// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mdct_float.c

#include <stdint.h>
#include <stdio.h>




typedef float FFTSample;

int
fn (FFTSample * output, int n, int n2, int k, int n4)
{
  for (k = 0; k < n4; k++)
    {
      output[k] = -output[n2 - k - 1];
      output[n - k - 1] = output[n2 + k];
    }
}

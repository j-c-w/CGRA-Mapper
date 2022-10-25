// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_headphone.c

#include <stdint.h>
#include <stdio.h>






int
fn (const float *src, const int in_channels, int wr, float *buffer[64], int l)
{
  for (l = 0; l < in_channels; l++)
    {
      *(buffer[l] + wr) = src[l];
    }
}

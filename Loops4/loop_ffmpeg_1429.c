// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_headphone.c

#include <stdint.h>
#include <stdio.h>






int
fn (const int in_channels, const int buffer_length, float *buffer[64], int l,
    float *ringbuffer)
{
  for (l = 0; l < in_channels; l++)
    {
      buffer[l] = ringbuffer + l * buffer_length;
    }
}

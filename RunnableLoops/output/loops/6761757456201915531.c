#include <stdint.h>
#include <stdio.h>






int
fn (const int in_channels, float *ringbuffer, const int buffer_length,
    float *buffer[64], int l)
{
  for (l = 0; l < in_channels; l++)
    {
      buffer[l] = ringbuffer + l * buffer_length;
    }
}

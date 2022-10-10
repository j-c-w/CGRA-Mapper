#include <stdint.h>
#include <stdio.h>






int
fn (const int in_channels, int wr, float *buffer[64], const float *src, int l)
{
  for (l = 0; l < in_channels; l++)
    {
      *(buffer[l] + wr) = src[l];
    }
}

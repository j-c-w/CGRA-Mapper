// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/cfhd.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int width, int16_t * high, int16_t * low)
{
  for (int i = 0; i < width; i++)
    {
      int even = (low[i] - high[i]) / 2;
      int odd = (low[i] + high[i]) / 2;
      low[i] = even;
      high[i] = odd;
}}

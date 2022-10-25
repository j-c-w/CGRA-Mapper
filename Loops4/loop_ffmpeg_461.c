// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/intrax8dsp.c

#include <stdint.h>
#include <stdio.h>






int
fn (uint16_t top_sum[2][8], uint16_t left_sum[2][8], int i)
{
  for (i = 0; i < 8; i++)
    {
      top_sum[0][i] += (top_sum[1][i] * 181 + 128) >> 8;
      left_sum[0][i] += (left_sum[1][i] * 181 + 128) >> 8;
    }
}

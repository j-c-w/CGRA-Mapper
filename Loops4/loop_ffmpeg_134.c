// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/synth_filter.c

#include <stdint.h>
#include <stdio.h>






int
fn (float c, const float *window, int i, float b, float a, float *synth_buf,
    int j, float d)
{
  for (; j < 1024; j += 128)
    {
      a += window[i + j] * (-synth_buf[31 - i + j - 1024]);
      b += window[i + j + 32] * (synth_buf[i + j - 1024]);
      c += window[i + j + 64] * (synth_buf[32 + i + j - 1024]);
      d += window[i + j + 96] * (synth_buf[63 - i + j - 1024]);
    }
}

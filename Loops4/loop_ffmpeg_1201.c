// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/synth_filter.c

#include <stdint.h>
#include <stdio.h>






int
fn (int *synth_buf_offset, float c, const float *window, int i, float b,
    float a, float *synth_buf, int j, float d)
{
  for (j = 0; j < 1024 - *synth_buf_offset; j += 128)
    {
      a += window[i + j] * (-synth_buf[31 - i + j]);
      b += window[i + j + 32] * (synth_buf[i + j]);
      c += window[i + j + 64] * (synth_buf[32 + i + j]);
      d += window[i + j + 96] * (synth_buf[63 - i + j]);
    }
}

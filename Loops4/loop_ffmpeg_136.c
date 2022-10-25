// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/synth_filter.c

#include <stdint.h>
#include <stdio.h>






int
fn (float c, const float *window, int i, float b, float a, float *synth_buf,
    int j, float d)
{
  for (; j < 512; j += 64)
    {
      a += window[i + j] * (-synth_buf[15 - i + j - 512]);
      b += window[i + j + 16] * (synth_buf[i + j - 512]);
      c += window[i + j + 32] * (synth_buf[16 + i + j - 512]);
      d += window[i + j + 48] * (synth_buf[31 - i + j - 512]);
    }
}

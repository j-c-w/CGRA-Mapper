#include <stdint.h>
#include <stdio.h>






int
fn (const float *window, float *synth_buf, int i, float a, float b, float c,
    int *synth_buf_offset, int j, float d)
{
  for (j = 0; j < 1024 - *synth_buf_offset; j += 128)
    {
      a += window[i + j] * (-synth_buf[31 - i + j]);
      b += window[i + j + 32] * (synth_buf[i + j]);
      c += window[i + j + 64] * (synth_buf[32 + i + j]);
      d += window[i + j + 96] * (synth_buf[63 - i + j]);
    }
}

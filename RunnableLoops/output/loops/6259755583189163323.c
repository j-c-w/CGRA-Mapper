#include <stdint.h>
#include <stdio.h>






int
fn (const float *window, float *synth_buf, int i, float a, float b,
    int *synth_buf_offset, float c, int j, float d)
{
  for (j = 0; j < 512 - *synth_buf_offset; j += 64)
    {
      a += window[i + j] * (-synth_buf[15 - i + j]);
      b += window[i + j + 16] * (synth_buf[i + j]);
      c += window[i + j + 32] * (synth_buf[16 + i + j]);
      d += window[i + j + 48] * (synth_buf[31 - i + j]);
    }
}

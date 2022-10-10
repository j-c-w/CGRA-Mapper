#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __int32_t int32_t;

int
fn (int64_t b, int64_t d, int32_t * synth_buf, int i, int64_t a,
    int *synth_buf_offset, int64_t c, const int32_t * window, int j)
{
  for (j = 0; j < 1024 - *synth_buf_offset; j += 128)
    {
      a += (int64_t) window[i + j] * synth_buf[i + j];
      b += (int64_t) window[i + j + 32] * synth_buf[31 - i + j];
      c += (int64_t) window[i + j + 64] * synth_buf[32 + i + j];
      d += (int64_t) window[i + j + 96] * synth_buf[63 - i + j];
    }
}

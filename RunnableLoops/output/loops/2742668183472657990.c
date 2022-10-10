#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __int32_t int32_t;

int
fn (int64_t b, int64_t d, int32_t * synth_buf, int i, int64_t a,
    const int32_t * window, int64_t c, int j)
{
  for (; j < 512; j += 64)
    {
      a += (int64_t) window[i + j] * synth_buf[i + j - 512];
      b += (int64_t) window[i + j + 16] * synth_buf[15 - i + j - 512];
      c += (int64_t) window[i + j + 32] * synth_buf[16 + i + j - 512];
      d += (int64_t) window[i + j + 48] * synth_buf[31 - i + j - 512];
    }
}

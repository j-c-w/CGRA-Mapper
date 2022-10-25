// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/synth_filter.c

#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __int32_t int32_t;

int
fn (int *synth_buf_offset, int i, const int32_t * window, int64_t d,
    int64_t a, int64_t b, int64_t c, int j, int32_t * synth_buf)
{
  for (j = 0; j < 1024 - *synth_buf_offset; j += 128)
    {
      a += (int64_t) window[i + j] * synth_buf[i + j];
      b += (int64_t) window[i + j + 32] * synth_buf[31 - i + j];
      c += (int64_t) window[i + j + 64] * synth_buf[32 + i + j];
      d += (int64_t) window[i + j + 96] * synth_buf[63 - i + j];
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavutil/fixed_dsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * dst, const int32_t * src1, int32_t wj, const int32_t * win,
    int32_t s0, int len, int32_t s1, int32_t i, const int32_t * src0,
    int32_t j, int32_t wi)
{
  for (i = -len, j = len - 1; i < 0; i++, j--)
    {
      s0 = src0[i];
      s1 = src1[j];
      wi = win[i];
      wj = win[j];
      dst[i] = ((int64_t) s0 * wj - (int64_t) s1 * wi + 0x40000000) >> 31;
      dst[j] = ((int64_t) s0 * wi + (int64_t) s1 * wj + 0x40000000) >> 31;
    }
}

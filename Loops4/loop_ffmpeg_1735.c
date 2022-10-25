// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/acelp_filters.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int frac_pos, const int16_t * in, int n,
    const int16_t * filter_coeffs, int filter_length, int precision)
{
  int idx = 0;
  int v = 0x4000;
  for (i = 0; i < filter_length;)
    {
      v += in[n + i] * filter_coeffs[idx + frac_pos];
      idx += precision;
      i++;
      v += in[n - i] * filter_coeffs[idx - frac_pos];
    }
}

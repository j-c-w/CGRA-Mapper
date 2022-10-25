// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/acelp_filters.c

#include <stdint.h>
#include <stdio.h>






int
fn (const float *filter_coeffs, int i, int frac_pos, float v, int n,
    int filter_length, const float *in, int precision)
{
  int idx = 0;
  for (i = 0; i < filter_length;)
    {
      v += in[n + i] * filter_coeffs[idx + frac_pos];
      idx += precision;
      i++;
      v += in[n - i] * filter_coeffs[idx - frac_pos];
    }
}

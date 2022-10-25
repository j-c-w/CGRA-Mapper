// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/acelp_filters.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *out, float tmp, float gain, int n, float *mem,
    const float *pole_coeffs, const float *in, const float *zero_coeffs)
{
  for (i = 0; i < n; i++)
    {
      tmp = gain * in[i] - pole_coeffs[0] * mem[0] - pole_coeffs[1] * mem[1];
      out[i] = tmp + zero_coeffs[0] * mem[0] + zero_coeffs[1] * mem[1];
      mem[1] = mem[0];
      mem[0] = tmp;
    }
}

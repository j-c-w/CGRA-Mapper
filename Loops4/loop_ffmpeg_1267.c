// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_headphone.c

#include <stdint.h>
#include <stdio.h>






int
fn (int I, float *ptr, float gain_lin, float *data_ir_l, int len, int j,
    int N, float *data_ir_r)
{
  for (j = 0; j < len; j++)
    {
      data_ir_l[j] = ptr[len * N - j * N - N + I] * gain_lin;
      data_ir_r[j] = ptr[len * N - j * N - N + I + 1] * gain_lin;
    }
}

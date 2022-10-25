// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_headphone.c

#include <stdint.h>
#include <stdio.h>






int
fn (float *ptr, float gain_lin, float *data_ir_l, int len, int j,
    float *data_ir_r)
{
  for (j = 0; j < len; j++)
    {
      data_ir_l[j] = ptr[len * 2 - j * 2 - 2] * gain_lin;
      data_ir_r[j] = ptr[len * 2 - j * 2 - 1] * gain_lin;
    }
}

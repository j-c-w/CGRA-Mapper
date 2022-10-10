#include <stdint.h>
#include <stdio.h>






int
fn (int len, float *data_ir_l, float *data_ir_r, float gain_lin, float *ptr,
    int j, int I, int N)
{
  for (j = 0; j < len; j++)
    {
      data_ir_l[j] = ptr[len * N - j * N - N + I] * gain_lin;
      data_ir_r[j] = ptr[len * N - j * N - N + I + 1] * gain_lin;
    }
}

#include <stdint.h>
#include <stdio.h>






int
fn (int len, float *data_ir_l, float *data_ir_r, float gain_lin, float *ptr,
    int j)
{
  for (j = 0; j < len; j++)
    {
      data_ir_l[j] = ptr[len * 2 - j * 2 - 2] * gain_lin;
      data_ir_r[j] = ptr[len * 2 - j * 2 - 1] * gain_lin;
    }
}

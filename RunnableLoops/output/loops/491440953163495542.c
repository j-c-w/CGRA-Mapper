#include <stdint.h>
#include <stdio.h>






int
fn (float *num, float *den, int i, float *bufferh, int j, float num_weight,
    const int block_size, float den_weight)
{
  for (j = 0; j < block_size; j++)
    {
      num[j] += bufferh[i * block_size + j] * num_weight;
      den[j] += den_weight;
    }
}

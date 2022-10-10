#include <stdint.h>
#include <stdio.h>






int
fn (float *num, int i, float *den, int j, float *bufferh, float num_weight,
    const int block_size, float den_weight)
{
  for (j = 0; j < block_size; j++)
    {
      num[j] += bufferh[i * block_size + j] * num_weight;
      den[j] += den_weight;
    }
}

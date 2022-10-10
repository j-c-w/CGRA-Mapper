#include <stdint.h>
#include <stdio.h>






int
fn (float *rbufferv, float *rbufferh, int i, float *bufferh, int j,
    const int block_size, float *bufferv)
{
  for (j = 0; j < block_size; j++)
    {
      bufferv[i * block_size + j] = bufferh[j * block_size + i];
      rbufferv[i * block_size + j] = rbufferh[j * block_size + i];
    }
}

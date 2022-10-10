#include <stdint.h>
#include <stdio.h>






int
fn (int i, int j, float *bufferh, const int block_size, float *bufferv)
{
  for (j = 0; j < block_size; j++)
    {
      bufferh[j * block_size + i] = bufferv[i * block_size + j];
    }
}

#include <stdint.h>
#include <stdio.h>






int
fn (float *bufferz, const int buffer_linesize, int i, int k, float *buffer,
    int j, const int nb_match_blocks, const int block_size)
{
  for (k = 0; k < nb_match_blocks; k++)
    {
      buffer[buffer_linesize * k + i * block_size + j] = bufferz[k];
    }
}

#include <stdint.h>
#include <stdio.h>






int
fn (float *bufferz, const int buffer_linesize, int i, int k, float *rbuffer,
    float *buffer, int j, const int nb_match_blocks, const int block_size,
    float *rbufferz)
{
  for (k = 0; k < nb_match_blocks; k++)
    {
      bufferz[k] = buffer[buffer_linesize * k + i * block_size + j];
      rbufferz[k] = rbuffer[buffer_linesize * k + i * block_size + j];
    }
}

#include <stdint.h>
#include <stdio.h>






int
fn (int i, int j, float *mlt_buffer_left, float *mlt_buffer_right,
    float *decode_buffer)
{
  for (j = 0; j < 20; j++)
    {
      mlt_buffer_left[i * 20 + j] = decode_buffer[i * 40 + j];
      mlt_buffer_right[i * 20 + j] = decode_buffer[i * 40 + 20 + j];
    }
}

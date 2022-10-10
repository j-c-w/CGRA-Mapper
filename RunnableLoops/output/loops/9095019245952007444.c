#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (float *ringbuffer, int wr, int j, float *dst, const uint32_t modulo,
    int n_read)
{
  for (j = 0; j < n_read; j++)
    {
      dst[2 * j] = ringbuffer[wr];
      ringbuffer[wr] = 0.0;
      wr = (wr + 1) & modulo;
    }
}

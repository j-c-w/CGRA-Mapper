// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dcahuff.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (uint32_t sum, uint8_t id, uint8_t i,
    const uint8_t bitalloc_12_bits[5][12], uint8_t sel, int *values,
    uint8_t n)
{
  for (i = 0; i < n; i++)
    {
      id = values[i] - 1;
      sum += bitalloc_12_bits[sel][id];
    }
}

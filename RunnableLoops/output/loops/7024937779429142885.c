#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const float gain, int i, int k, int group, const uint16_t * offsets,
    const float *src, float *dest)
{
  for (k = offsets[i]; k < offsets[i + 1]; k++)
    {
      dest[group * 128 + k] += gain * src[group * 128 + k];
    }
}

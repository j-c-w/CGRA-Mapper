#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * d, unsigned int value, int bits_per_plane, int pixels_per_value,
    int j, int xl, unsigned int mask)
{
  for (; xl < pixels_per_value; xl++)
    {
      j = (j < bits_per_plane ? 8 : j) - bits_per_plane;
      d[xl] |= (value >> j) & mask;
    }
}

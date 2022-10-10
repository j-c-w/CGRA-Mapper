#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int pulse_count, const uint8_t * tab1, int i, int pulse_indexes, int mask,
    int16_t * fc_v, int pulse_signs, int bits)
{
  for (i = 0; i < pulse_count; i++)
    {
      fc_v[i + tab1[pulse_indexes & mask]] +=
	(pulse_signs & 1) ? 8191 : -8192;
      pulse_indexes >>= bits;
      pulse_signs >>= 1;
    }
}

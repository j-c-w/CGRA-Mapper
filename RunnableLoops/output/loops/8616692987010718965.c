#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int16_t * mask, int band, int i, int seg, int delta,
    uint8_t * dba_lengths)
{
  for (i = 0; i < dba_lengths[seg]; i++)
    {
      mask[band++] += delta;
    }
}

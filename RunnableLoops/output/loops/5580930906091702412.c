#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int cb_gain, int16_t * vector, int i, int cb_sign, int offset, int cb_pos,
    int cb_shift)
{
  for (i = 0; i < 8; i += 2)
    {
      offset = ((cb_pos & 7) << 3) + cb_shift + i;
      vector[offset] = (cb_sign & 1) ? cb_gain : -cb_gain;
      cb_pos >>= 3;
      cb_sign >>= 1;
    }
}

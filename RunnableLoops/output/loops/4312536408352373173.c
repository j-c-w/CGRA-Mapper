#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint32_t uint32_t;

int
fn (int i, uint32_t xordata, uint32_t magdata, int32_t * samples_l,
    uint32_t ordata, int nb_samples, uint32_t anddata)
{
  uint32_t crc = 0xffffffffu;
  for (i = 0; i < nb_samples; i++)
    {
      int32_t M = samples_l[i];
      crc = crc * 9 + (M & 0xffff) * 3 + ((M >> 16) & 0xffff);
      magdata |= (M < 0) ? ~M : M;
      xordata |= M ^ -(M & 1);
      anddata &= M;
      ordata |= M;
    }
}

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int ga, int sh_fact, int i, int gt, int16_t * out, int16_t * res_pst,
    int fact, int tmp2, int subframe_size)
{
  for (i = subframe_size - 1; i >= 1; i--)
    {
      tmp2 = (gt * res_pst[i - 1]) * 2 + 0x4000;
      tmp2 = res_pst[i] + (tmp2 >> 15);
      tmp2 = (tmp2 * ga + fact) >> sh_fact;
      out[i] = tmp2;
    }
}

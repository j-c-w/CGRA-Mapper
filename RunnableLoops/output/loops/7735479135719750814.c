#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int lsfq_min_distance, int i, int16_t * lsfq, int lp_order, int lsfq_min)
{
  for (i = 0; i < lp_order; i++)
    {
      lsfq[i] = ((lsfq[i]) > (lsfq_min) ? (lsfq[i]) : (lsfq_min));
      lsfq_min = lsfq[i] + lsfq_min_distance;
    }
}

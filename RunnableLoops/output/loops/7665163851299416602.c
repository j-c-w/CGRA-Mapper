#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (int32_t * row, const int16_t * lpc, int order, int k)
{
  int DC_resp = 0;
  for (k = 0; k < order; k++)
    {
      DC_resp += lpc[k];
      row[k] = lpc[k] * 4096;
    }
}

#include <stdint.h>
#include <stdio.h>




typedef __int8_t int8_t;
typedef __int16_t int16_t;

int
fn (int8_t * exp, int bin, int start, int16_t * psd, int end)
{
  for (bin = start; bin < end; bin++)
    {
      psd[bin] = (3072 - (exp[bin] << 7));
    }
}

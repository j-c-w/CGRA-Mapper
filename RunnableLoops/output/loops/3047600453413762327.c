#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (unsigned int a1, int i, int32_t * coeffs, int length)
{
  for (i = 0; i < length - 1 >> 1; i++)
    {
      *coeffs += a1;
      coeffs[1] += (unsigned) *coeffs;
      a1 = coeffs[1];
      coeffs += 2;
}}

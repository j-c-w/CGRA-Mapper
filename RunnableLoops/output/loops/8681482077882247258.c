#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int length, unsigned int a1, int i, int32_t * coeffs, unsigned int a2)
{
  for (i = 0; i < length - 2 >> 1; i++)
    {
      unsigned a3 = *coeffs + a1;
      unsigned a4 = a3 + a2;
      *coeffs = a4;
      a1 = coeffs[1] + a3;
      a2 = a1 + a4;
      coeffs[1] = a2;
      coeffs += 2;
}}

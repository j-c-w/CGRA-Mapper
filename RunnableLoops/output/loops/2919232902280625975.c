#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef double TXSample;

int
fn (TXSample * dst, ptrdiff_t stride, int len, int len2, int len4)
{
  for (int i = 0; i < len4; i++)
    {
      dst[i * stride] = -dst[(len2 - i - 1) * stride];
      dst[(len - i - 1) * stride] = dst[(len2 + i + 0) * stride];
}}

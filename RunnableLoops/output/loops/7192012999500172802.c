#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (int coef_count, int *coef_idx, const uint32_t * quant, int i,
    const uint8_t * scan, int32_t * block)
{
  for (i = 0; i < coef_count; i++)
    {
      int idx = coef_idx[i];
      block[scan[idx]] = (int) (block[scan[idx]] * quant[idx]) >> 11;
}}

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int base, int num_bands, int k, int16_t * bands, int prod, int previous,
    int present)
{
  for (k = 0; k < num_bands - 1; k++)
    {
      prod = (int) (((int64_t) prod * base + 0x400000) >> 23);
      present = (prod + 0x400000) >> 23;
      bands[k] = present - previous;
      previous = present;
}}

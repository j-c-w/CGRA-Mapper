#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int base, int k, int16_t * bands, int previous, int prod, int num_bands,
    int present)
{
  for (k = 0; k < num_bands - 1; k++)
    {
      prod = (int) (((int64_t) prod * base + 0x400000) >> 23);
      present = (prod + 0x400000) >> 23;
      bands[k] = present - previous;
      previous = present;
}}

#include <stdint.h>
#include <stdio.h>






int
fn (const int len, const int *src, int round, int i, int c,
    unsigned int *dest, int tmp, int shift)
{
  for (i = 0; i < len; i++)
    {
      tmp = (int) (((int64_t) src[i] * c + (int64_t) 0x1000000000) >> 37);
      dest[i] += (tmp + round) >> shift;
}}

#include <stdint.h>
#include <stdio.h>






int
fn (unsigned int round, int len, int i, int c, int *src, int ssign, int s,
    int out, int *dst)
{
  for (i = 0; i < len; i++)
    {
      out = (int) (((int64_t) src[i] * c) >> 32);
      dst[i] = ((int) (out + round) >> s) * ssign;
}}

#include <stdint.h>
#include <stdio.h>






int
fn (unsigned int round, int len, int i, int c, int *coefs, int s, int out)
{
  for (i = 0; i < len; i++)
    {
      out = (int) (((int64_t) coefs[i] * c) >> 32);
      coefs[i] = -((int) (out + round) >> s);
}}

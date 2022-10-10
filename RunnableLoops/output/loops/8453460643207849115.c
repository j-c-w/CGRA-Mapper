#include <stdint.h>
#include <stdio.h>






int
fn (int i, int *v2, int len, unsigned int *v1)
{
  for (i = 0; i < len; i++)
    {
      int t = v1[i] - v2[i];
      v1[i] += v2[i];
      v2[i] = t;
}}

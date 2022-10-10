#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *__restrict v2, float *__restrict v1, int len)
{
  for (i = 0; i < len; i++)
    {
      float t = v1[i] - v2[i];
      v1[i] += v2[i];
      v2[i] = t;
}}

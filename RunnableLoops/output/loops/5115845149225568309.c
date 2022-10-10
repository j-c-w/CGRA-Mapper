#include <stdint.h>
#include <stdio.h>






int
fn (float *__restrict v1, float *__restrict v2, int len, int i)
{
  for (i = 0; i < len; i++)
    {
      float t = v1[i] - v2[i];
      v1[i] += v2[i];
      v2[i] = t;
}}

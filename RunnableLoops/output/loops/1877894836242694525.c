#include <stdint.h>
#include <stdio.h>






int
fn (float cpe, float *fixed_vector, float last, int i)
{
  for (i = 1; i < 64 - 1; i++)
    {
      float cur = fixed_vector[i];
      fixed_vector[i] -= cpe * (last + fixed_vector[i + 1]);
      last = cur;
}}

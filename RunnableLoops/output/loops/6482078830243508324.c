#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t * refp, int x, const int block_size, const uint16_t * srcp)
{
  double dist = 0.;
  for (x = 0; x < block_size; x++)
    {
      double temp = refp[x] - srcp[x];
      dist += temp * temp;
}}

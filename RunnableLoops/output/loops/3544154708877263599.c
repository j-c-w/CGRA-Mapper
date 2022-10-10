#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int j, int bw, uint16_t * pix)
{
  int sqsum = 0;
  int sum = 0;
  for (j = 0; j < bw; ++j)
    {
      const int sample = (unsigned) pix[j] >> 6;
      sum += sample;
      sqsum += sample * sample;
}}

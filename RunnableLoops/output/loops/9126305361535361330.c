#include <stdint.h>
#include <stdio.h>






int
fn (float *su2, int nsample, int band, float *su1)
{
  for (; nsample < band + 256; nsample++)
    {
      float c1 = su1[nsample];
      float c2 = su2[nsample];
      su1[nsample] = c1 + c2;
      su2[nsample] = c1 - c2;
}}

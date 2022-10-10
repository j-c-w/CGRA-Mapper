#include <stdint.h>
#include <stdio.h>






int
fn (float *B, float eps, float *meanI, float *meanP, float *meanII, float *A,
    float *meanIP, int w)
{
  int i = 0;
  for (int j = 0; j < w; j++)
    {
      int x = i * w + j;
      float varI = meanII[x] - (meanI[x] * meanI[x]);
      float covIP = meanIP[x] - (meanI[x] * meanP[x]);
      A[x] = covIP / (varI + eps);
      B[x] = meanP[x] - A[x] * meanI[x];
}}

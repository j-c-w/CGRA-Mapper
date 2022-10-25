// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_guided.c

#include <stdint.h>
#include <stdio.h>






int
fn (int w, float *B, float *meanI, float *meanP, float *meanII, float *meanIP,
    float eps, float *A)
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

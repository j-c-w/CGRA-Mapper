// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_arnndn.c

#include <stdint.h>
#include <stdio.h>




typedef struct AVComplexFloat
{
  float re, im;
} AVComplexFloat;

int
fn (float rf[481], AVComplexFloat * X, const AVComplexFloat * P)
{
  for (int i = 0; i < ((120 << 2) + 1); i++)
    {
      X[i].re += rf[i] * P[i].re;
      X[i].im += rf[i] * P[i].im;
}}

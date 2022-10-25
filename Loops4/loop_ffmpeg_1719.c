// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_arnndn.c

#include <stdint.h>
#include <stdio.h>




typedef struct AVComplexFloat
{
  float re, im;
} AVComplexFloat;
typedef __uint8_t uint8_t;

int
fn (float sum[22], int band_size, const uint8_t eband5ms[22],
    const AVComplexFloat * X, const AVComplexFloat * P)
{
  int i = 0;
  for (int j = 0; j < band_size; j++)
    {
      float tmp, frac = (float) j / band_size;
      tmp = X[(eband5ms[i] << 2) + j].re * P[(eband5ms[i] << 2) + j].re;
      tmp += X[(eband5ms[i] << 2) + j].im * P[(eband5ms[i] << 2) + j].im;
      sum[i] += (1 - frac) * tmp;
      sum[i + 1] += frac * tmp;
}}

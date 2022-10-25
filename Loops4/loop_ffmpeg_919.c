// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_arnndn.c

#include <stdint.h>
#include <stdio.h>




typedef struct AVComplexFloat
{
  float re, im;
} AVComplexFloat;

int
fn (AVComplexFloat x[960])
{
  for (int i = ((120 << 2) + 1); i < (2 * (120 << 2)); i++)
    {
      x[i].re = x[(2 * (120 << 2)) - i].re;
      x[i].im = -x[(2 * (120 << 2)) - i].im;
}}

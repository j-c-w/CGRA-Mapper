// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_arnndn.c

#include <stdint.h>
#include <stdio.h>




typedef struct AVComplexFloat
{
  float re, im;
} AVComplexFloat;

int
fn (const float *in, AVComplexFloat x[960])
{
  for (int i = 0; i < (2 * (120 << 2)); i++)
    {
      x[i].re = in[i];
      x[i].im = 0;
}}

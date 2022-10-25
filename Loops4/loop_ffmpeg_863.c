// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/flacenc.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int i, int n, int c, int a, const int32_t * smp, int32_t * res, int order)
{
  for (i = order; i < n; i += 2)
    {
      int b = smp[i] - smp[i - 1];
      int d = b - a;
      res[i] = d - c;
      a = smp[i + 1] - smp[i];
      c = a - b;
      res[i + 1] = c - d;
}}

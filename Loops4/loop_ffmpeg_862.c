// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/flacenc.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int i, int e, int n, int c, int a, const int32_t * smp, int32_t * res,
    int order)
{
  for (i = order; i < n; i += 2)
    {
      int b = smp[i] - smp[i - 1];
      int d = b - a;
      int f = d - c;
      res[i] = f - e;
      a = smp[i + 1] - smp[i];
      c = a - b;
      e = c - d;
      res[i + 1] = e - f;
}}

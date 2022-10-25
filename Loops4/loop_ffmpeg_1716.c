// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/speexdec.c

#include <stdint.h>
#include <stdio.h>






int
fn (float xx1[352], float y2, const int M2, float y0, float x10, float x20,
    float xx2[352], const float *a, float y1, const int N2, float y3)
{
  int i = 0;
  for (int j = 0; j < M2; j += 2)
    {
      float x11, x21;
      float a0, a1;
      a0 = a[2 * j];
      a1 = a[2 * j + 1];
      x11 = xx1[N2 - 1 + j - i];
      x21 = xx2[N2 - 1 + j - i];
      y0 += a0 * (x11 - x21);
      y1 += a1 * (x11 + x21);
      y2 += a0 * (x10 - x20);
      y3 += a1 * (x10 + x20);
      a0 = a[2 * j + 2];
      a1 = a[2 * j + 3];
      x10 = xx1[N2 + j - i];
      x20 = xx2[N2 + j - i];
      y0 += a0 * (x10 - x20);
      y1 += a1 * (x10 + x20);
      y2 += a0 * (x11 - x21);
      y3 += a1 * (x11 + x21);
}}

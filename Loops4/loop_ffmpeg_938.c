// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_arnndn.c

#include <stdint.h>
#include <stdio.h>






int
fn (float xy01, const float *y01, const float *y02, float xy02,
    const float *x, int N)
{
  for (int i = 0; i < N; i++)
    {
      xy01 += (x[i] * y01[i]);
      xy02 += (x[i] * y02[i]);
}}

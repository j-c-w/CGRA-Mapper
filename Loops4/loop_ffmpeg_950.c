// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_arnndn.c

#include <stdint.h>
#include <stdio.h>






int
fn (int overlap, const float *window, float xx[864], int n, const float *x)
{
  for (int i = 0; i < overlap; i++)
    {
      xx[i] = x[i] * window[i];
      xx[n - i - 1] = x[n - i - 1] * window[i];
}}

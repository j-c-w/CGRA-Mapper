// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavutil/float_dsp.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *dst, const float *win, const float *src0, int len,
    const float *src1, int j)
{
  for (i = -len, j = len - 1; i < 0; i++, j--)
    {
      float s0 = src0[i];
      float s1 = src1[j];
      float wi = win[i];
      float wj = win[j];
      dst[i] = s0 * wj - s1 * wi;
      dst[j] = s0 * wi + s1 * wj;
}}

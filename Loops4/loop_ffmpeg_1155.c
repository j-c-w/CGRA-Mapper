// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_acrossover.c

#include <stdint.h>
#include <stdio.h>






int
fn (const float *src, const float b2, int nb_samples, float *dst,
    const float b1, const float b0, float z1, float z2, const float a1,
    const float a2)
{
  for (int n = 0; n + 1 < nb_samples; n++)
    {
      float in = src[n];
      float out;
      out = in * b0 + z1;
      z1 = b1 * in + z2 + a1 * out;
      z2 = b2 * in + a2 * out;
      dst[n] = out;
      n++;
      in = src[n];
      out = in * b0 + z1;
      z1 = b1 * in + z2 + a1 * out;
      z2 = b2 * in + a2 * out;
      dst[n] = out;
}}

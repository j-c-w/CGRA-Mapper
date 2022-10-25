// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_acrossover.c

#include <stdint.h>
#include <stdio.h>






int
fn (const double b0, const double *src, int nb_samples, const double b2,
    const double a1, double z1, const double b1, double z2, double *dst,
    const double a2)
{
  for (int n = 0; n + 1 < nb_samples; n++)
    {
      double in = src[n];
      double out;
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

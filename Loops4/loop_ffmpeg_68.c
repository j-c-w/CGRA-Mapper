// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_aiir.c

#include <stdint.h>
#include <stdio.h>






int
fn (double p0, const double *k, const double *v, double n0,
    const int nb_stages, double n1, double *x)
{
  double out = 0.;
  for (int i = nb_stages - 1; i >= 0; i--)
    {
      n0 = n1 - k[i] * x[i];
      p0 = n0 * k[i] + x[i];
      out += p0 * v[i + 1];
      x[i] = p0;
      n1 = n0;
}}

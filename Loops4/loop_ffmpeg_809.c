// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_curves.c

#include <stdint.h>
#include <stdio.h>






int
fn (double *r, const int n, int i, double (*matrix)[3])
{
  for (i = 1; i < n; i++)
    {
      const double den = matrix[i][1] - matrix[i][0] * matrix[i - 1][2];
      const double k = den ? 1. / den : 1.;
      matrix[i][2] *= k;
      r[i] = (r[i] - matrix[i][0] * r[i - 1]) * k;
}}

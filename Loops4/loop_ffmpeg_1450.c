// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/x86/af_afir_init.c

#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;

int
fn (ptrdiff_t len, int n, const double *t, const double *c, double *sum)
{
  for (n = 0; n < len; n++)
    {
      const double cre = c[2 * n];
      const double cim = c[2 * n + 1];
      const double tre = t[2 * n];
      const double tim = t[2 * n + 1];
      sum[2 * n] += tre * cre - tim * cim;
      sum[2 * n + 1] += tre * cim + tim * cre;
}}

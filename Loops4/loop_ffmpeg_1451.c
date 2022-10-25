// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/x86/af_afir_init.c

#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;

int
fn (const float *c, ptrdiff_t len, const float *t, float *sum, int n)
{
  for (n = 0; n < len; n++)
    {
      const float cre = c[2 * n];
      const float cim = c[2 * n + 1];
      const float tre = t[2 * n];
      const float tim = t[2 * n + 1];
      sum[2 * n] += tre * cre - tim * cim;
      sum[2 * n + 1] += tre * cim + tim * cre;
}}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/wmavoice.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const double *old, double *a1, int n, const float (*ipol_tab)[2][10],
    uint16_t interpol, double *i_lsps)
{
  for (n = 0; n < 10; n++)
    {
      double delta = old[n] - i_lsps[n];
      a1[n] = ipol_tab[interpol][0][n] * delta + i_lsps[n];
      a1[10 + n] = ipol_tab[interpol][1][n] * delta + i_lsps[n];
}}

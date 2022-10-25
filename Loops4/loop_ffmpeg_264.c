// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_thumbnail.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, double sum_sq_err, const int *hist, const double *median,
    double err)
{
  for (i = 0; i < (3 * 256); i++)
    {
      err = median[i] - (double) hist[i];
      sum_sq_err += err * err;
}}

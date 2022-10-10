#include <stdint.h>
#include <stdio.h>






int
fn (double thigh, const double *lp, const double *hp, int buff_idx,
    int buffer_length, double *buffer, int wavelet_length)
{
  double tlow = 0.0;
  for (int j = 0; j < wavelet_length; j++)
    {
      const int idx = ((-j + buff_idx - 1) & ((buffer_length) - 1));
      const double btemp = buffer[idx];
      thigh += btemp * hp[j];
      tlow += btemp * lp[j];
}}

#include <stdint.h>
#include <stdio.h>






int
fn (double thigh, const double *lp, const double *hp, int buff_idx,
    int buffer_length, double *buffer, int wavelet_length)
{
  double tlow = 0.0;
  for (int i = 0; i < wavelet_length; i++)
    {
      const int idx = ((-i + buff_idx - 1) & ((buffer_length) - 1));
      const double btemp = buffer[idx];
      thigh += btemp * hp[i];
      tlow += btemp * lp[i];
}}

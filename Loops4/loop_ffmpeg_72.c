// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_afwtdn.c

#include <stdint.h>
#include <stdio.h>






int
fn (double thigh, const double *hp, int buff_idx, int buffer_length,
    int wavelet_length, const double *lp, double *buffer)
{
  double tlow = 0.0;
  for (int i = 0; i < wavelet_length; i++)
    {
      const int idx = ((-i + buff_idx - 1) & ((buffer_length) - 1));
      const double btemp = buffer[idx];
      thigh += btemp * hp[i];
      tlow += btemp * lp[i];
}}

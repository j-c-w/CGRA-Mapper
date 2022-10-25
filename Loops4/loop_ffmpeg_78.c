// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/opusenc_psy.c

#include <stdint.h>
#include <stdio.h>






int
fn (float avg_c_s, const int range, const float *coeffs)
{
  float dist_dev = 0.0f;
  int j = 0;
  for (j = 0; j < range; j++)
    {
      const float c_s = coeffs[j] * coeffs[j];
      dist_dev += (avg_c_s - c_s) * (avg_c_s - c_s);
}}

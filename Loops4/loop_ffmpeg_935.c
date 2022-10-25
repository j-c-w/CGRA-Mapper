// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_arnndn.c

#include <stdint.h>
#include <stdio.h>






int
fn (float *features, float *ceps_2, float *ceps_1, float *ceps_0)
{
  for (int i = 0; i < 6; i++)
    {
      features[i] = ceps_0[i] + ceps_1[i] + ceps_2[i];
      features[22 + i] = ceps_0[i] - ceps_2[i];
      features[22 + 6 + i] = ceps_0[i] - 2 * ceps_1[i] + ceps_2[i];
}}

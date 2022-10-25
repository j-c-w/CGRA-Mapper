// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ac3dsp.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, float surround_mix, float center_mix, float front_mix, int len,
    float **samples)
{
  for (i = 0; i < len; i++)
    {
      samples[0][i] =
	samples[0][i] * front_mix + samples[1][i] * center_mix +
	samples[2][i] * front_mix + samples[3][i] * surround_mix +
	samples[4][i] * surround_mix;
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_arnndn.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int band_size, float *g, const float *bandE,
    const uint8_t eband5ms[22])
{
  int i = 0;
  for (int j = 0; j < band_size; j++)
    {
      float frac = (float) j / band_size;
      g[(eband5ms[i] << 2) + j] =
	(1.f - frac) * bandE[i] + frac * bandE[i + 1];
}}

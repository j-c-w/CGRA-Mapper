// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/opus_celt.c

#include <stdint.h>
#include <stdio.h>






int
fn (float *data, float x3, float x4, int i, float g12, float g02, float x1,
    const int T0, float x2, float g01, const int T1,
    const float ff_celt_window2[120], float x0, float g11, float g10,
    float g00)
{
  for (i = 0; i < 120; i++)
    {
      float w = ff_celt_window2[i];
      x0 = data[i - T1 + 2];
      data[i] +=
	(1.0 - w) * g00 * data[i - T0] + (1.0 - w) * g01 * (data[i - T0 - 1] +
							    data[i - T0 +
								 1]) + (1.0 -
									w) *
	g02 * (data[i - T0 - 2] + data[i - T0 + 2]) + w * g10 * x2 +
	w * g11 * (x1 + x3) + w * g12 * (x0 + x4);
      x4 = x3;
      x3 = x2;
      x2 = x1;
      x1 = x0;
}}

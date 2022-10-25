// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ac3dsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int64_t int64_t;
typedef __int16_t int16_t;

int
fn (int i, int64_t v0, int16_t front_mix, int16_t surround_mix, int64_t v1,
    int len, int32_t ** samples, int16_t center_mix)
{
  for (i = 0; i < len; i++)
    {
      v0 =
	(int64_t) samples[0][i] * front_mix +
	(int64_t) samples[1][i] * center_mix +
	(int64_t) samples[3][i] * surround_mix;
      v1 =
	(int64_t) samples[1][i] * center_mix +
	(int64_t) samples[2][i] * front_mix +
	(int64_t) samples[4][i] * surround_mix;
      samples[0][i] = (v0 + 2048) >> 12;
      samples[1][i] = (v1 + 2048) >> 12;
    }
}

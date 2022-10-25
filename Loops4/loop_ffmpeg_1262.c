// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ac3dsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int16_t int16_t;
typedef __int64_t int64_t;

int
fn (int i, int64_t v0, int16_t ** matrix, int in_ch, int64_t v1,
    int32_t ** samples, int j)
{
  for (j = 0; j < in_ch; j++)
    {
      v0 += (int64_t) samples[j][i] * matrix[0][j];
      v1 += (int64_t) samples[j][i] * matrix[1][j];
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ac3dsp.c

#include <stdint.h>
#include <stdio.h>






int
fn (float **matrix, int i, int in_ch, float v1, int j, float **samples,
    float v0)
{
  for (j = 0; j < in_ch; j++)
    {
      v0 += samples[j][i] * matrix[0][j];
      v1 += samples[j][i] * matrix[1][j];
    }
}

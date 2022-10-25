// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mpegaudiodec_float.c

#include <stdint.h>
#include <stdio.h>






int
fn (float *tab0, float v2, float *tab1, float tmp0, int len, float v1, int j)
{
  for (j = 0; j < len; j++)
    {
      tmp0 = tab0[j];
      tab0[j] = ((v1) * (tmp0));
      tab1[j] = ((v2) * (tmp0));
    }
}

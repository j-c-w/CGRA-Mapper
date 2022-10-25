// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mpegaudiodec_fixed.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, int *tab0, unsigned int tmp0, int *tab1, unsigned int tmp1)
{
  for (i = 0; i < 576; i++)
    {
      tmp0 = tab0[i];
      tmp1 = tab1[i];
      tab0[i] = tmp0 + tmp1;
      tab1[i] = tmp0 - tmp1;
    }
}

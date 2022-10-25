// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/atrac.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, float s2, float *p1, float s1, float qmf_window[48])
{
  for (i = 0; i < 48; i += 2)
    {
      s1 += p1[i] * qmf_window[i];
      s2 += p1[i + 1] * qmf_window[i + 1];
    }
}

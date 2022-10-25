// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/aacps_float.c

#include <stdint.h>
#include <stdio.h>




typedef __int8_t int8_t;

int
fn (int8_t * opd_hist, int8_t * ipd_hist, int i)
{
  for (i = 0; i < 17; i++)
    {
      opd_hist[i] = 0;
      ipd_hist[i] = 0;
    }
}

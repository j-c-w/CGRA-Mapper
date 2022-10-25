// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ivi_dsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * buf, int j, int16_t tmp[64], int i)
{
  for (j = 0; j < 8; j++)
    {
      (buf[j]) += (tmp[i * 8 + j] >> 1);
    }
}

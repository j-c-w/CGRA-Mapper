// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ivi_dsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * buf, int j, int16_t tmp[16], int i)
{
  for (j = 0; j < 4; j++)
    {
      (buf[j]) = (tmp[i * 4 + j] >> 1);
    }
}

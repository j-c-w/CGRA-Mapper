// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ivi_dsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * buf, int j, const int16_t * ref_buf)
{
  for (j = 0; j < 8; j++)
    {
      (buf[j]) = (ref_buf[j]);
    }
}

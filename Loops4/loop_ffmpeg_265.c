// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/g723_1dec.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int *rseed, int gain, int i, int16_t * out)
{
  for (i = 0; i < (60 << 2); i++)
    {
      *rseed = (int16_t) (*rseed * 521 + 259);
      out[i] = gain * *rseed >> 15;
    }
}

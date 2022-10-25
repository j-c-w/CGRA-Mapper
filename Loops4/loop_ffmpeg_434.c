// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/g723_1dec.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int offset, int i, int cb_gain, int cb_shift, int cb_pos,
    int16_t * vector, int cb_sign)
{
  for (i = 0; i < 8; i += 2)
    {
      offset = ((cb_pos & 7) << 3) + cb_shift + i;
      vector[offset] = (cb_sign & 1) ? cb_gain : -cb_gain;
      cb_pos >>= 3;
      cb_sign >>= 1;
    }
}

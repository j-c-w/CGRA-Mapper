// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ac3enc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int nb_groups, int k, uint8_t * exp, int cpl)
{
  for (i = nb_groups, k = (nb_groups * 4) - cpl; i > 0; i--)
    {
      exp[k] = exp[k - 1] = exp[k - 2] = exp[k - 3] = exp[i - cpl];
      k -= 4;
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ac3enc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int nb_groups, int k, uint8_t * exp, int cpl)
{
  for (i = nb_groups, k = (nb_groups * 2) - cpl; i > 0; i--)
    {
      uint8_t exp1 = exp[i - cpl];
      exp[k--] = exp1;
      exp[k--] = exp1;
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/dsp/enc_sse2.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int distribution[32], int k, int16_t out[16])
{
  for (k = 0; k < 16; ++k)
    {
      ++distribution[out[k]];
    }
}

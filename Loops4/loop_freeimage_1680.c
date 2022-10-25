// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/dsp/dec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int j, uint8_t * dst)
{
  int DC = 16;
  for (j = 0; j < 16; ++j)
    {
      DC += dst[-1 + j * 32] + dst[j - 32];
    }
}

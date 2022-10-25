// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/dsp/dec_sse2.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * dst, int i)
{
  int dc0 = 4;
  for (i = 0; i < 8; ++i)
    {
      dc0 += dst[-1 + i * 32];
    }
}

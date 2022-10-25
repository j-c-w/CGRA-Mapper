// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/dec/frame_dec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int j, uint8_t * const y_dst)
{
  for (j = 0; j < 16; ++j)
    {
      y_dst[j * 32 - 1] = 129;
    }
}

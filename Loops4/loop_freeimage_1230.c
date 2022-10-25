// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/dec/frame_dec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * const v_dst, uint8_t * const u_dst, int j)
{
  for (j = 0; j < 8; ++j)
    {
      u_dst[j * 32 - 1] = 129;
      v_dst[j * 32 - 1] = 129;
    }
}

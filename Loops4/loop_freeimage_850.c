// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/mux/anim_encode.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int width, int i, uint32_t * const dst, int left)
{
  for (i = left; i < left + width; ++i)
    {
      dst[i] = 0x00000000;
    }
}

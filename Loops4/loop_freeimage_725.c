// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/enc/alpha_enc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t color[256], int width, const uint8_t * const p, int i)
{
  for (i = 0; i < width; ++i)
    {
      color[p[i]] = 1;
    }
}

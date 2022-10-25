// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/enc/iterator_enc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * const top, int i)
{
  for (i = 0; i <= 3; ++i)
    {
      top[i] = top[i + 4];
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/dsp/enc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * const clip_table, int x, int size, const uint8_t * top,
    uint8_t * dst)
{
  for (x = 0; x < size; ++x)
    {
      dst[x] = clip_table[top[x]];
    }
}

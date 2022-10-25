// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/dec/vp8l_dec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;

int
fn (uint64_t pattern, int length, uint32_t * dst, int i)
{
  for (i = 0; i < (length >> 1); ++i)
    {
      ((uint64_t *) dst)[i] = pattern;
    }
}

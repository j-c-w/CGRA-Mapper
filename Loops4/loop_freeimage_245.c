// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/dec/vp8l_dec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * src, int length, uint8_t * dst, int i)
{
  for (i <<= 2; i < length; ++i)
    {
      dst[i] = src[i];
    }
}

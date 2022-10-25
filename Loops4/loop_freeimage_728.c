// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/dsp/alpha_processing.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (uint32_t * dst, int width, const uint8_t * alpha, int i)
{
  for (i = 0; i < width; ++i)
    {
      dst[i] = alpha[i] << 8;
    }
}

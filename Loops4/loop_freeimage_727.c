// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/dsp/alpha_processing.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int width, uint8_t * alpha, uint8_t alpha_mask,
    const uint8_t * argb)
{
  for (i = 0; i < width; ++i)
    {
      const uint8_t alpha_value = argb[4 * i];
      alpha[i] = alpha_value;
      alpha_mask &= alpha_value;
}}

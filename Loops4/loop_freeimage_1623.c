// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/utils/quant_levels_dec_utils.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;

int
fn (const int r, int x, const uint16_t * const in, const uint32_t scale,
    uint16_t * const out)
{
  for (x = 0; x <= r; ++x)
    {
      const uint16_t delta = in[x + r - 1] + in[r - x];
      out[x] = (delta * scale) >> 16;
}}

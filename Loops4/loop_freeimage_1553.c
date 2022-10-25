// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/utils/quant_levels_dec_utils.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (uint16_t sum, int x, const int w, const uint16_t * const top,
    const uint8_t * src, uint16_t * const out, uint16_t * const cur)
{
  for (x = 0; x < w; ++x)
    {
      uint16_t new_value;
      sum += src[x];
      new_value = top[x] + sum;
      out[x] = new_value - cur[x];
      cur[x] = new_value;
    }
}

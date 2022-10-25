// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/enc/picture_csp_enc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (uint32_t * const argb_dst, int x, const uint8_t * const src,
    const int width)
{
  for (x = 0; x < width; ++x)
    {
      argb_dst[x] = (argb_dst[x] & 0x00ffffffu) | ((uint32_t) src[x] << 24);
    }
}

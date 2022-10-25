// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/dec/io_dec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (int i, uint32_t alpha_mask, const int mb_w, uint8_t * alpha_dst,
    const uint8_t * alpha)
{
  for (i = 0; i < mb_w; ++i)
    {
      const uint32_t alpha_value = alpha[i] >> 4;
      alpha_dst[2 * i] = (alpha_dst[2 * i] & 0xf0) | alpha_value;
      alpha_mask &= alpha_value;
}}

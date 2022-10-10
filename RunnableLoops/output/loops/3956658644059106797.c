#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * dst, int num_pixels, int i, const uint8_t * src)
{
  for (i = 0; i < num_pixels; i++)
    {
      unsigned rgb = ((const uint16_t *) src)[i];
      ((uint16_t *) dst)[i] =
	((rgb & 0x7C00) >> 10) | ((rgb & 0x3E0) << 1) | (rgb << 11);
}}

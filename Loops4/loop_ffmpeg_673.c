// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/rgb2rgb.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int num_pixels, uint8_t * dst, const uint8_t * src, int i)
{
  for (i = 0; i < num_pixels; i++)
    {
      unsigned rgb = ((const uint16_t *) src)[i];
      ((uint16_t *) dst)[i] = (rgb >> 11) | (rgb & 0x7E0) | (rgb << 11);
}}

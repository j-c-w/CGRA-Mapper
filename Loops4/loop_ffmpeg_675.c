// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/rgb2rgb.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int num_pixels, uint16_t * s, int i, uint16_t * d)
{
  for (i = 0; i < num_pixels; i++)
    {
      unsigned rgb = s[i];
      d[i] = (rgb << 8 | rgb & 0xF0 | rgb >> 8) & 0xFFF;
}}

// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/image.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, unsigned char *tga_pixel, int tga_height, int tga_comp,
    int tga_width)
{
  for (i = 0; i < tga_width * tga_height; ++i)
    {
      unsigned char temp = tga_pixel[0];
      tga_pixel[0] = tga_pixel[2];
      tga_pixel[2] = temp;
      tga_pixel += tga_comp;
}}

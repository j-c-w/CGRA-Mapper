// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/image.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, unsigned char *tga_data, int index1, int tga_comp, int tga_width,
    int index2)
{
  for (i = tga_width * tga_comp; i > 0; --i)
    {
      unsigned char temp = tga_data[index1];
      tga_data[index1] = tga_data[index2];
      tga_data[index2] = temp;
      ++index1;
      ++index2;
}}

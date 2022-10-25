// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibTIFF4/tif_predict.c

#include <stdint.h>
#include <stdio.h>




typedef signed long tmsize_t;

int
fn (unsigned char *cp, tmsize_t i, tmsize_t stride)
{
  for (i = stride - 4; i > 0; i--)
    {
      cp[stride] = (unsigned char) ((cp[stride] + *cp) & 0xff);
      cp++;
}}

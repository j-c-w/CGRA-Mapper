// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibTIFF4/tif_jpeg.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned char JSAMPLE;

int
fn (int xpos, JSAMPLE * outptr, int padding)
{
  for (xpos = 0; xpos < padding; xpos++)
    {
      *outptr = outptr[-1];
      outptr++;
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/jxrgluelib/JXRGluePFC.c

#include <stdint.h>
#include <stdio.h>




typedef int I32;
typedef unsigned char U8;
typedef int Bool;

int
fn (I32 x, I32 n, Bool bBlackWhite, U8 * piDstPixel, const U8 v)
{
  for (n = 0; n < 8; n++)
    {
      piDstPixel[8 * x + n] =
	(((v >> (7 - n)) & 0x1) != 0) ^ bBlackWhite ? 0xFF : 0x00;
    }
}

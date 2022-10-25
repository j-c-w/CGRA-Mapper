// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/image.c

#include <stdint.h>
#include <stdio.h>






int
fn (const int UVQT[64], int i, unsigned char UVTable[64],
    unsigned char YTable[64], int quality, const int YQT[64],
    const unsigned char stbiw__jpg_ZigZag[64])
{
  for (i = 0; i < 64; ++i)
    {
      int uvti, yti = (YQT[i] * quality + 50) / 100;
      YTable[stbiw__jpg_ZigZag[i]] =
	(unsigned char) (yti < 1 ? 1 : yti > 255 ? 255 : yti);
      uvti = (UVQT[i] * quality + 50) / 100;
      UVTable[stbiw__jpg_ZigZag[i]] =
	(unsigned char) (uvti < 1 ? 1 : uvti > 255 ? 255 : uvti);
}}

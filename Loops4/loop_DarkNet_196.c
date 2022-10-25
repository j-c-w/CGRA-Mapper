// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/image.c

#include <stdint.h>
#include <stdio.h>






int
fn (const float aasf[8], int col, float fdtbl_Y[64],
    unsigned char UVTable[64], int k, unsigned char YTable[64], int row,
    float fdtbl_UV[64], const unsigned char stbiw__jpg_ZigZag[64])
{
  for (col = 0; col < 8; ++col, ++k)
    {
      fdtbl_Y[k] = 1 / (YTable[stbiw__jpg_ZigZag[k]] * aasf[row] * aasf[col]);
      fdtbl_UV[k] =
	1 / (UVTable[stbiw__jpg_ZigZag[k]] * aasf[row] * aasf[col]);
    }
}

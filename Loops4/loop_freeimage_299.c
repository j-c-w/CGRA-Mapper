// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibTIFF4/tif_pixarlog.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned short uint16;

int
fn (float *ToLinearF, int j, int i, uint16 * From14)
{
  for (i = 0; i < 16384; i++)
    {
      while ((i / 16383.) * (i / 16383.) > ToLinearF[j] * ToLinearF[j + 1])
	j++;
      From14[i] = (uint16) j;
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJPEG/jdcolor.c

#include <stdint.h>
#include <stdio.h>




typedef long INT32;

int
fn (INT32 i, INT32 * rgb_y_tab)
{
  for (i = 0; i <= 255; i++)
    {
      rgb_y_tab[i + 0] = ((INT32) ((0.299) * (1L << 16) + 0.5)) * i;
      rgb_y_tab[i + (1 * (255 + 1))] =
	((INT32) ((0.587) * (1L << 16) + 0.5)) * i;
      rgb_y_tab[i + (2 * (255 + 1))] =
	((INT32) ((0.114) * (1L << 16) + 0.5)) * i + ((INT32) 1 << (16 - 1));
    }
}

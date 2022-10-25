// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJPEG/jccolor.c

#include <stdint.h>
#include <stdio.h>




typedef long INT32;

int
fn (INT32 * rgb_ycc_tab, INT32 i)
{
  for (i = 0; i <= 255; i++)
    {
      rgb_ycc_tab[i + 0] = ((INT32) ((0.299) * (1L << 16) + 0.5)) * i;
      rgb_ycc_tab[i + (1 * (255 + 1))] =
	((INT32) ((0.587) * (1L << 16) + 0.5)) * i;
      rgb_ycc_tab[i + (2 * (255 + 1))] =
	((INT32) ((0.114) * (1L << 16) + 0.5)) * i + ((INT32) 1 << (16 - 1));
      rgb_ycc_tab[i + (3 * (255 + 1))] =
	(-((INT32) ((0.168735892) * (1L << 16) + 0.5))) * i;
      rgb_ycc_tab[i + (4 * (255 + 1))] =
	(-((INT32) ((0.331264108) * (1L << 16) + 0.5))) * i;
      rgb_ycc_tab[i + (5 * (255 + 1))] =
	((INT32) ((0.5) * (1L << 16) + 0.5)) * i + ((INT32) 128 << 16) +
	((INT32) 1 << (16 - 1)) - 1;
      rgb_ycc_tab[i + (6 * (255 + 1))] =
	(-((INT32) ((0.418687589) * (1L << 16) + 0.5))) * i;
      rgb_ycc_tab[i + (7 * (255 + 1))] =
	(-((INT32) ((0.081312411) * (1L << 16) + 0.5))) * i;
    }
}

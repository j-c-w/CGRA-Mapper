// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJPEG/jquant1.c

#include <stdint.h>
#include <stdio.h>






int
fn (int *Ncolors, int iroot, int i, int total_colors, int nc)
{
  for (i = 0; i < nc; i++)
    {
      Ncolors[i] = iroot;
      total_colors *= iroot;
    }
}

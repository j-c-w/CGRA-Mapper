// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/enc/predictor_enc.c

#include <stdint.h>
#include <stdio.h>






int
fn (int (*best_histo)[256], int j, int i, int (*accumulated)[256])
{
  for (j = 0; j < 256; j++)
    {
      accumulated[i][j] += best_histo[i][j];
    }
}

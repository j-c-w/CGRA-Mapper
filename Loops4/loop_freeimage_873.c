// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibTIFF4/tif_predict.c

#include <stdint.h>
#include <stdio.h>




typedef signed long tmsize_t;
typedef unsigned int uint32;

int
fn (tmsize_t i, uint32 * wp, tmsize_t stride)
{
  for (i = stride - 4; i > 0; i--)
    {
      wp[stride] -= wp[0];
      wp--;
    }
}

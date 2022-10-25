// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibTIFF4/tif_predict.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned char uint8;
typedef unsigned int uint32;
typedef signed long tmsize_t;

int
fn (uint32 bps, tmsize_t wc, uint32 byte, uint8 * cp, uint8 * tmp,
    tmsize_t count)
{
  for (byte = 0; byte < bps; byte++)
    {
      cp[(bps - byte - 1) * wc + count] = tmp[bps * count + byte];
    }
}

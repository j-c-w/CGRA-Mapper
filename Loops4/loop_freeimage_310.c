// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibTIFF4/tif_pixarlog.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned short uint16;

int
fn (int i, double v, float *ToLinearF, unsigned char *ToLinear8,
    uint16 * ToLinear16)
{
  for (i = 0; i < 2049; i++)
    {
      v = ToLinearF[i] * 65535.0 + 0.5;
      ToLinear16[i] = (v > 65535.0) ? 65535 : (uint16) v;
      v = ToLinearF[i] * 255.0 + 0.5;
      ToLinear8[i] = (v > 255.0) ? 255 : (unsigned char) v;
}}

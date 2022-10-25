// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibTIFF4/tif_pixarlog.c

#include <stdint.h>
#include <stdio.h>






int
fn (double linstep, int i, double v, float *ToLinearF, int nlin, int j)
{
  for (i = 0; i < nlin; i++)
    {
      v = i * linstep;
      ToLinearF[j++] = (float) v;
}}

// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibOpenJPEG/dwt.c

#include <stdint.h>
#include <stdio.h>




typedef int32_t OPJ_INT32;
typedef float OPJ_FLOAT32;

int
fn (OPJ_FLOAT32 * __restrict bi, OPJ_INT32 count, OPJ_INT32 x,
    OPJ_FLOAT32 * __restrict a, OPJ_INT32 i)
{
  for (i = 0; i < count; ++i)
    {
      OPJ_INT32 j = i;
      bi[i * 8] = a[j];
      j += x;
      bi[i * 8 + 1] = a[j];
      j += x;
      bi[i * 8 + 2] = a[j];
      j += x;
      bi[i * 8 + 3] = a[j];
    }
}

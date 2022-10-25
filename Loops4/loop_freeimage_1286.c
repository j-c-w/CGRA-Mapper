// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibOpenJPEG/jp2.c

#include <stdint.h>
#include <stdio.h>




typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;

int
fn (OPJ_INT32 * dst, OPJ_UINT32 j, OPJ_INT32 * src, OPJ_UINT32 max)
{
  for (j = 0; j < max; ++j)
    {
      dst[j] = src[j];
    }
}

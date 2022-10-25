// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibOpenJPEG/mct.c

#include <stdint.h>
#include <stdio.h>




typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;

int
fn (OPJ_UINT32 i, OPJ_INT32 * __restrict c0, OPJ_UINT32 n,
    OPJ_INT32 * __restrict c2, OPJ_INT32 * __restrict c1)
{
  for (i = 0; i < n; ++i)
    {
      OPJ_INT32 y = c0[i];
      OPJ_INT32 u = c1[i];
      OPJ_INT32 v = c2[i];
      OPJ_INT32 g = y - ((u + v) >> 2);
      OPJ_INT32 r = v + g;
      OPJ_INT32 b = u + g;
      c0[i] = r;
      c1[i] = g;
      c2[i] = b;
    }
}

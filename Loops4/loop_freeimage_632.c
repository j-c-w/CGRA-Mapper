// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibOpenJPEG/mct.c

#include <stdint.h>
#include <stdio.h>




typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;

int
fn (OPJ_INT32 * __restrict c0, OPJ_UINT32 n, OPJ_INT32 * __restrict c2,
    OPJ_INT32 * __restrict c1, OPJ_UINT32 i)
{
  for (i = 0; i < n; ++i)
    {
      OPJ_INT32 r = c0[i];
      OPJ_INT32 g = c1[i];
      OPJ_INT32 b = c2[i];
      OPJ_INT32 y = (r + (g * 2) + b) >> 2;
      OPJ_INT32 u = b - g;
      OPJ_INT32 v = r - g;
      c0[i] = y;
      c1[i] = u;
      c2[i] = v;
    }
}

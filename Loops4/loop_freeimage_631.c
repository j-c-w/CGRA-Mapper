// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibOpenJPEG/mct.c

#include <stdint.h>
#include <stdio.h>




typedef float OPJ_FLOAT32;
typedef uint32_t OPJ_UINT32;

int
fn (OPJ_FLOAT32 * __restrict c1, OPJ_UINT32 n, OPJ_FLOAT32 * __restrict c2,
    OPJ_UINT32 i, OPJ_FLOAT32 * __restrict c0)
{
  for (i = 0; i < n; ++i)
    {
      OPJ_FLOAT32 y = c0[i];
      OPJ_FLOAT32 u = c1[i];
      OPJ_FLOAT32 v = c2[i];
      OPJ_FLOAT32 r = y + (v * 1.402f);
      OPJ_FLOAT32 g = y - (u * 0.34413f) - (v * (0.71414f));
      OPJ_FLOAT32 b = y + (u * 1.772f);
      c0[i] = r;
      c1[i] = g;
      c2[i] = b;
    }
}

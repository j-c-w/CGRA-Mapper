// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibOpenJPEG/dwt.c

#include <stdint.h>
#include <stdio.h>




typedef int32_t OPJ_INT32;

int
fn (OPJ_INT32 * bj, OPJ_INT32 k, OPJ_INT32 w, OPJ_INT32 rh, OPJ_INT32 * aj)
{
  for (k = 0; k < rh; ++k)
    {
      bj[k] = aj[k * w];
    }
}

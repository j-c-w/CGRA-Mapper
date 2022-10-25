// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibOpenJPEG/mct.c

#include <stdint.h>
#include <stdio.h>




typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;

int
fn (OPJ_UINT32 pNbComp, OPJ_UINT32 j, OPJ_INT32 ** lData,
    OPJ_INT32 * lCurrentData)
{
  for (j = 0; j < pNbComp; ++j)
    {
      lCurrentData[j] = (*(lData[j]));
    }
}

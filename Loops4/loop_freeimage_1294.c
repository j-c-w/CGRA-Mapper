// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibOpenJPEG/mct.c

#include <stdint.h>
#include <stdio.h>




typedef float OPJ_FLOAT32;
typedef uint32_t OPJ_UINT32;

int
fn (OPJ_UINT32 pNbComp, OPJ_UINT32 j, OPJ_FLOAT32 ** lData,
    OPJ_FLOAT32 * lCurrentData)
{
  for (j = 0; j < pNbComp; ++j)
    {
      lCurrentData[j] = (OPJ_FLOAT32) (*(lData[j]));
    }
}

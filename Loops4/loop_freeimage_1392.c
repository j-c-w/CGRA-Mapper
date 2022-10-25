// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibOpenJPEG/mct.c

#include <stdint.h>
#include <stdio.h>




typedef uint32_t OPJ_UINT32;
typedef float OPJ_FLOAT32;

int
fn (OPJ_FLOAT32 * lMct, OPJ_FLOAT32 * lCurrentData,
    OPJ_FLOAT32 * lCurrentResult, OPJ_UINT32 pNbComp, OPJ_UINT32 j,
    OPJ_UINT32 k)
{
  for (k = 0; k < pNbComp; ++k)
    {
      lCurrentResult[j] += *(lMct++) * lCurrentData[k];
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibOpenJPEG/mct.c

#include <stdint.h>
#include <stdio.h>




typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;
typedef float OPJ_FLOAT32;

int
fn (OPJ_FLOAT32 * lMct, OPJ_INT32 * lCurrentMatrix, OPJ_UINT32 lNbMatCoeff,
    OPJ_UINT32 lMultiplicator, OPJ_UINT32 i)
{
  for (i = 0; i < lNbMatCoeff; ++i)
    {
      lCurrentMatrix[i] =
	(OPJ_INT32) (*(lMct++) * (OPJ_FLOAT32) lMultiplicator);
    }
}

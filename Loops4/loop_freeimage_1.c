// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/decode/segdec.c

#include <stdint.h>
#include <stdio.h>




typedef int Int;

int
fn (Int aTemp[16], Int k, Int aRLCoeffs[32], Int iNumNonzero)
{
  Int iIndex = 0;
  for (k = 0; k < iNumNonzero; k++)
    {
      iIndex += aRLCoeffs[k * 2];
      aTemp[iIndex & 0xf] = aRLCoeffs[k * 2 + 1];
      iIndex++;
    }
}

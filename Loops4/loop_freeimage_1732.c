// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/encode/segenc.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned int U32;
typedef struct CAdaptiveScan
{
  U32 uTotal;
  U32 uScan;
} CAdaptiveScan;
typedef int Int;

int
fn (Int k, int iWeight, CAdaptiveScan * pScan)
{
  int iScale = 2;
  for (k = 1; k < 16; k++)
    {
      pScan[k].uTotal = iWeight;
      iWeight -= iScale;
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/decode/postprocess.c

#include <stdint.h>
#include <stdio.h>




typedef int Int;
typedef unsigned char U8;
typedef struct tagPostProcInfo
{
  Int iMBDC;
  U8 ucMBTexture;
  Int iBlockDC[4][4];
  U8 ucBlockTexture[4][4];
} tagPostProcInfo;
typedef long unsigned int size_t;

int
fn (struct tagPostProcInfo *pMBa, Int dc[5][5], size_t j, U8 texture[5][5],
    size_t i)
{
  for (i = 0; i < 4; i++)
    {
      dc[j][i] = pMBa->iBlockDC[j][i];
      texture[j][i] = pMBa->ucBlockTexture[j][i];
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJPEG/jfdctint.c

#include <stdint.h>
#include <stdio.h>




typedef long INT32;
typedef int DCTELEM;

int
fn (INT32 tmp0, DCTELEM * dataptr, int ctr, INT32 tmp1)
{
  for (ctr = 0; ctr < 4; ctr++)
    {
      tmp0 = dataptr[8 * 0] + (((INT32) 1) << (2 - 1));
      tmp1 = dataptr[8 * 1];
      dataptr[8 * 0] = (DCTELEM) ((tmp0 + tmp1) >> (2));
      dataptr[8 * 1] = (DCTELEM) ((tmp0 - tmp1) >> (2));
      dataptr++;
    }
}

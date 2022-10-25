// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJPEG/jfdctint.c

#include <stdint.h>
#include <stdio.h>




typedef int DCTELEM;
typedef long INT32;

int
fn (INT32 tmp11, INT32 tmp0, INT32 tmp1, DCTELEM * dataptr, int ctr,
    INT32 tmp10)
{
  for (ctr = 0; ctr < 2; ctr++)
    {
      tmp0 = dataptr[8 * 0] + dataptr[8 * 3];
      tmp1 = dataptr[8 * 1] + dataptr[8 * 2];
      tmp10 = dataptr[8 * 0] - dataptr[8 * 3];
      tmp11 = dataptr[8 * 1] - dataptr[8 * 2];
      dataptr[8 * 0] = (DCTELEM) (tmp0 + tmp1);
      dataptr[8 * 2] = (DCTELEM) (tmp0 - tmp1);
      tmp0 = ((tmp10 + tmp11) * (((INT32) 4433)));
      tmp0 += ((INT32) 1) << (13 - 1);
      dataptr[8 * 1] =
	(DCTELEM) ((tmp0 + ((tmp10) * (((INT32) 6270)))) >> (13));
      dataptr[8 * 3] =
	(DCTELEM) ((tmp0 - ((tmp11) * (((INT32) 15137)))) >> (13));
      dataptr++;
    }
}

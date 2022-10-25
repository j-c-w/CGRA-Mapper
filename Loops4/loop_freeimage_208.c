// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJPEG/jfdctint.c

#include <stdint.h>
#include <stdio.h>




typedef long INT32;
typedef int DCTELEM;

int
fn (INT32 tmp2, INT32 z1, INT32 tmp11, INT32 tmp3, INT32 tmp0, INT32 tmp12,
    INT32 tmp13, INT32 tmp1, DCTELEM * dataptr, int ctr, INT32 tmp10)
{
  for (ctr = 0; ctr < 4; ctr++)
    {
      tmp0 = dataptr[8 * 0] + dataptr[8 * 7];
      tmp1 = dataptr[8 * 1] + dataptr[8 * 6];
      tmp2 = dataptr[8 * 2] + dataptr[8 * 5];
      tmp3 = dataptr[8 * 3] + dataptr[8 * 4];
      tmp10 = tmp0 + tmp3 + (((INT32) 1) << (2 - 1));
      tmp12 = tmp0 - tmp3;
      tmp11 = tmp1 + tmp2;
      tmp13 = tmp1 - tmp2;
      tmp0 = dataptr[8 * 0] - dataptr[8 * 7];
      tmp1 = dataptr[8 * 1] - dataptr[8 * 6];
      tmp2 = dataptr[8 * 2] - dataptr[8 * 5];
      tmp3 = dataptr[8 * 3] - dataptr[8 * 4];
      dataptr[8 * 0] = (DCTELEM) ((tmp10 + tmp11) >> (2));
      dataptr[8 * 4] = (DCTELEM) ((tmp10 - tmp11) >> (2));
      z1 = ((tmp12 + tmp13) * (((INT32) 4433)));
      z1 += ((INT32) 1) << (13 + 2 - 1);
      dataptr[8 * 2] =
	(DCTELEM) ((z1 + ((tmp12) * (((INT32) 6270)))) >> (13 + 2));
      dataptr[8 * 6] =
	(DCTELEM) ((z1 - ((tmp13) * (((INT32) 15137)))) >> (13 + 2));
      tmp12 = tmp0 + tmp2;
      tmp13 = tmp1 + tmp3;
      z1 = ((tmp12 + tmp13) * (((INT32) 9633)));
      z1 += ((INT32) 1) << (13 + 2 - 1);
      tmp12 = ((tmp12) * (-((INT32) 3196)));
      tmp13 = ((tmp13) * (-((INT32) 16069)));
      tmp12 += z1;
      tmp13 += z1;
      z1 = ((tmp0 + tmp3) * (-((INT32) 7373)));
      tmp0 = ((tmp0) * (((INT32) 12299)));
      tmp3 = ((tmp3) * (((INT32) 2446)));
      tmp0 += z1 + tmp12;
      tmp3 += z1 + tmp13;
      z1 = ((tmp1 + tmp2) * (-((INT32) 20995)));
      tmp1 = ((tmp1) * (((INT32) 25172)));
      tmp2 = ((tmp2) * (((INT32) 16819)));
      tmp1 += z1 + tmp13;
      tmp2 += z1 + tmp12;
      dataptr[8 * 1] = (DCTELEM) ((tmp0) >> (13 + 2));
      dataptr[8 * 3] = (DCTELEM) ((tmp1) >> (13 + 2));
      dataptr[8 * 5] = (DCTELEM) ((tmp2) >> (13 + 2));
      dataptr[8 * 7] = (DCTELEM) ((tmp3) >> (13 + 2));
      dataptr++;
    }
}

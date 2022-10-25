// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJPEG/jfdctint.c

#include <stdint.h>
#include <stdio.h>




typedef long INT32;
typedef int DCTELEM;

int
fn (INT32 tmp2, INT32 tmp11, INT32 tmp0, INT32 tmp1, DCTELEM * dataptr,
    int ctr, INT32 tmp10)
{
  for (ctr = 0; ctr < 5; ctr++)
    {
      tmp0 = dataptr[8 * 0] + dataptr[8 * 4];
      tmp1 = dataptr[8 * 1] + dataptr[8 * 3];
      tmp2 = dataptr[8 * 2];
      tmp10 = tmp0 + tmp1;
      tmp11 = tmp0 - tmp1;
      tmp0 = dataptr[8 * 0] - dataptr[8 * 4];
      tmp1 = dataptr[8 * 1] - dataptr[8 * 3];
      dataptr[8 * 0] =
	(DCTELEM) (((((tmp10 +
		       tmp2) *
		      (((INT32) ((1.28) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      tmp11 =
	((tmp11) * (((INT32) ((1.011928851) * (((INT32) 1) << 13) + 0.5))));
      tmp10 -= tmp2 << 2;
      tmp10 =
	((tmp10) * (((INT32) ((0.452548340) * (((INT32) 1) << 13) + 0.5))));
      dataptr[8 * 2] =
	(DCTELEM) (((tmp11 + tmp10) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr[8 * 4] =
	(DCTELEM) (((tmp11 - tmp10) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      tmp10 =
	((tmp0 +
	  tmp1) * (((INT32) ((1.064004961) * (((INT32) 1) << 13) + 0.5))));
      dataptr[8 * 1] =
	(DCTELEM) (((tmp10 +
		     ((tmp0) *
		      (((INT32)
			((0.657591230) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr[8 * 3] =
	(DCTELEM) (((tmp10 -
		     ((tmp1) *
		      (((INT32)
			((2.785601151) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr++;
    }
}

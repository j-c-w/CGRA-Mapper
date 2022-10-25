// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJPEG/jfdctint.c

#include <stdint.h>
#include <stdio.h>




typedef long INT32;
typedef int DCTELEM;

int
fn (INT32 tmp2, INT32 tmp11, INT32 tmp0, INT32 tmp12, INT32 tmp1,
    DCTELEM * dataptr, int ctr, INT32 tmp10)
{
  for (ctr = 8 - 1; ctr >= 0; ctr--)
    {
      tmp0 = dataptr[8 * 0] + dataptr[8 * 5];
      tmp11 = dataptr[8 * 1] + dataptr[8 * 4];
      tmp2 = dataptr[8 * 2] + dataptr[8 * 3];
      tmp10 = tmp0 + tmp2;
      tmp12 = tmp0 - tmp2;
      tmp0 = dataptr[8 * 0] - dataptr[8 * 5];
      tmp1 = dataptr[8 * 1] - dataptr[8 * 4];
      tmp2 = dataptr[8 * 2] - dataptr[8 * 3];
      dataptr[8 * 0] =
	(DCTELEM) (((((tmp10 +
		       tmp11) *
		      (((INT32)
			((1.777777778) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
      dataptr[8 * 2] =
	(DCTELEM) (((((tmp12) *
		      (((INT32)
			((2.177324216) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
      dataptr[8 * 4] =
	(DCTELEM) (((((tmp10 - tmp11 -
		       tmp11) *
		      (((INT32)
			((1.257078722) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
      tmp10 =
	((tmp0 +
	  tmp2) * (((INT32) ((0.650711829) * (((INT32) 1) << 13) + 0.5))));
      dataptr[8 * 1] =
	(DCTELEM) (((tmp10 +
		     ((tmp0 +
		       tmp1) *
		      (((INT32)
			((1.777777778) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
      dataptr[8 * 3] =
	(DCTELEM) (((((tmp0 - tmp1 -
		       tmp2) *
		      (((INT32)
			((1.777777778) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
      dataptr[8 * 5] =
	(DCTELEM) (((tmp10 +
		     ((tmp2 -
		       tmp1) *
		      (((INT32)
			((1.777777778) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
      dataptr++;
    }
}

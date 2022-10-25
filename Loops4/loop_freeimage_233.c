// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJPEG/jfdctint.c

#include <stdint.h>
#include <stdio.h>




typedef int DCTELEM;
typedef long INT32;

int
fn (INT32 tmp2, DCTELEM * wsptr, INT32 tmp14, INT32 tmp4, INT32 tmp11,
    INT32 tmp0, INT32 tmp3, INT32 tmp12, INT32 tmp13, INT32 tmp1,
    DCTELEM * dataptr, int ctr, INT32 tmp10)
{
  for (ctr = 8 - 1; ctr >= 0; ctr--)
    {
      tmp0 = dataptr[8 * 0] + wsptr[8 * 1];
      tmp1 = dataptr[8 * 1] + wsptr[8 * 0];
      tmp12 = dataptr[8 * 2] + dataptr[8 * 7];
      tmp3 = dataptr[8 * 3] + dataptr[8 * 6];
      tmp4 = dataptr[8 * 4] + dataptr[8 * 5];
      tmp10 = tmp0 + tmp4;
      tmp13 = tmp0 - tmp4;
      tmp11 = tmp1 + tmp3;
      tmp14 = tmp1 - tmp3;
      tmp0 = dataptr[8 * 0] - wsptr[8 * 1];
      tmp1 = dataptr[8 * 1] - wsptr[8 * 0];
      tmp2 = dataptr[8 * 2] - dataptr[8 * 7];
      tmp3 = dataptr[8 * 3] - dataptr[8 * 6];
      tmp4 = dataptr[8 * 4] - dataptr[8 * 5];
      dataptr[8 * 0] =
	(DCTELEM) (((((tmp10 + tmp11 +
		       tmp12) *
		      (((INT32) ((1.28) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      tmp12 += tmp12;
      dataptr[8 * 4] =
	(DCTELEM) (((((tmp10 -
		       tmp12) *
		      (((INT32) ((1.464477191) * (((INT32) 1) << 13) + 0.5))))
		     -
		     ((tmp11 -
		       tmp12) *
		      (((INT32)
			((0.559380511) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      tmp10 =
	((tmp13 +
	  tmp14) * (((INT32) ((1.064004961) * (((INT32) 1) << 13) + 0.5))));
      dataptr[8 * 2] =
	(DCTELEM) (((tmp10 +
		     ((tmp13) *
		      (((INT32)
			((0.657591230) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr[8 * 6] =
	(DCTELEM) (((tmp10 -
		     ((tmp14) *
		      (((INT32)
			((2.785601151) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      tmp10 = tmp0 + tmp4;
      tmp11 = tmp1 - tmp3;
      dataptr[8 * 5] =
	(DCTELEM) (((((tmp10 - tmp11 -
		       tmp2) *
		      (((INT32) ((1.28) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      tmp2 = ((tmp2) * (((INT32) ((1.28) * (((INT32) 1) << 13) + 0.5))));
      dataptr[8 * 1] =
	(DCTELEM) (((((tmp0) *
		      (((INT32) ((1.787906876) * (((INT32) 1) << 13) + 0.5))))
		     +
		     ((tmp1) *
		      (((INT32) ((1.612894094) * (((INT32) 1) << 13) + 0.5))))
		     + tmp2 +
		     ((tmp3) *
		      (((INT32) ((0.821810588) * (((INT32) 1) << 13) + 0.5))))
		     +
		     ((tmp4) *
		      (((INT32)
			((0.283176630) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      tmp12 =
	((tmp0 -
	  tmp4) * (((INT32) ((1.217352341) * (((INT32) 1) << 13) + 0.5)))) -
	((tmp1 +
	  tmp3) * (((INT32) ((0.752365123) * (((INT32) 1) << 13) + 0.5))));
      tmp13 =
	((tmp10 +
	  tmp11) * (((INT32) ((0.395541753) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp11) * (((INT32) ((0.64) * (((INT32) 1) << 13) + 0.5)))) - tmp2;
      dataptr[8 * 3] =
	(DCTELEM) (((tmp12 + tmp13) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr[8 * 7] =
	(DCTELEM) (((tmp12 - tmp13) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr++;
      wsptr++;
    }
}

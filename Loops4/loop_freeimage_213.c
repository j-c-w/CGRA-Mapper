// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJPEG/jfdctint.c

#include <stdint.h>
#include <stdio.h>




typedef long INT32;
typedef int DCTELEM;

int
fn (INT32 tmp2, DCTELEM * wsptr, INT32 tmp14, INT32 tmp5, INT32 tmp15,
    INT32 tmp11, INT32 tmp4, INT32 tmp0, INT32 tmp3, INT32 tmp12, INT32 tmp13,
    INT32 tmp1, DCTELEM * dataptr, int ctr, INT32 tmp10)
{
  for (ctr = 0; ctr < 6; ctr++)
    {
      tmp0 = dataptr[8 * 0] + wsptr[8 * 3];
      tmp1 = dataptr[8 * 1] + wsptr[8 * 2];
      tmp2 = dataptr[8 * 2] + wsptr[8 * 1];
      tmp3 = dataptr[8 * 3] + wsptr[8 * 0];
      tmp4 = dataptr[8 * 4] + dataptr[8 * 7];
      tmp5 = dataptr[8 * 5] + dataptr[8 * 6];
      tmp10 = tmp0 + tmp5;
      tmp13 = tmp0 - tmp5;
      tmp11 = tmp1 + tmp4;
      tmp14 = tmp1 - tmp4;
      tmp12 = tmp2 + tmp3;
      tmp15 = tmp2 - tmp3;
      tmp0 = dataptr[8 * 0] - wsptr[8 * 3];
      tmp1 = dataptr[8 * 1] - wsptr[8 * 2];
      tmp2 = dataptr[8 * 2] - wsptr[8 * 1];
      tmp3 = dataptr[8 * 3] - wsptr[8 * 0];
      tmp4 = dataptr[8 * 4] - dataptr[8 * 7];
      tmp5 = dataptr[8 * 5] - dataptr[8 * 6];
      dataptr[8 * 0] =
	(DCTELEM) (((((tmp10 + tmp11 +
		       tmp12) *
		      (((INT32)
			((0.888888889) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr[8 * 6] =
	(DCTELEM) (((((tmp13 - tmp14 -
		       tmp15) *
		      (((INT32)
			((0.888888889) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr[8 * 4] =
	(DCTELEM) (((((tmp10 -
		       tmp12) *
		      (((INT32)
			((1.088662108) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr[8 * 2] =
	(DCTELEM) (((((tmp14 -
		       tmp15) *
		      (((INT32) ((0.888888889) * (((INT32) 1) << 13) + 0.5))))
		     +
		     ((tmp13 +
		       tmp15) *
		      (((INT32)
			((1.214244803) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      tmp10 =
	((tmp1 +
	  tmp4) * (((INT32) ((0.481063200) * (((INT32) 1) << 13) + 0.5))));
      tmp14 =
	tmp10 +
	((tmp1) * (((INT32) ((0.680326102) * (((INT32) 1) << 13) + 0.5))));
      tmp15 =
	tmp10 -
	((tmp4) * (((INT32) ((1.642452502) * (((INT32) 1) << 13) + 0.5))));
      tmp12 =
	((tmp0 +
	  tmp2) * (((INT32) ((0.997307603) * (((INT32) 1) << 13) + 0.5))));
      tmp13 =
	((tmp0 +
	  tmp3) * (((INT32) ((0.765261039) * (((INT32) 1) << 13) + 0.5))));
      tmp10 =
	tmp12 + tmp13 + tmp14 -
	((tmp0) * (((INT32) ((0.516244403) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp5) * (((INT32) ((0.164081699) * (((INT32) 1) << 13) + 0.5))));
      tmp11 =
	((tmp2 +
	  tmp3) * (-((INT32) ((0.164081699) * (((INT32) 1) << 13) + 0.5))));
      tmp12 +=
	tmp11 - tmp15 -
	((tmp2) * (((INT32) ((2.079550144) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp5) * (((INT32) ((0.765261039) * (((INT32) 1) << 13) + 0.5))));
      tmp13 +=
	tmp11 - tmp14 +
	((tmp3) * (((INT32) ((0.645144899) * (((INT32) 1) << 13) + 0.5)))) -
	((tmp5) * (((INT32) ((0.997307603) * (((INT32) 1) << 13) + 0.5))));
      tmp11 =
	tmp15 +
	((tmp0 -
	  tmp3) * (((INT32) ((1.161389302) * (((INT32) 1) << 13) + 0.5)))) -
	((tmp2 +
	  tmp5) * (((INT32) ((0.481063200) * (((INT32) 1) << 13) + 0.5))));
      dataptr[8 * 1] =
	(DCTELEM) (((tmp10) + (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr[8 * 3] =
	(DCTELEM) (((tmp11) + (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr[8 * 5] =
	(DCTELEM) (((tmp12) + (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr[8 * 7] =
	(DCTELEM) (((tmp13) + (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr++;
      wsptr++;
    }
}

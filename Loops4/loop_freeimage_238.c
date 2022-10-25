// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJPEG/jfdctint.c

#include <stdint.h>
#include <stdio.h>




typedef int DCTELEM;
typedef long INT32;

int
fn (INT32 tmp4, INT32 z1, INT32 tmp7, DCTELEM * dataptr, INT32 tmp15,
    INT32 tmp11, INT32 tmp1, int ctr, INT32 tmp16, INT32 z3, INT32 tmp6,
    INT32 tmp3, INT32 tmp0, INT32 tmp13, INT32 z2, INT32 tmp10, INT32 tmp2,
    DCTELEM * wsptr, INT32 tmp14, INT32 tmp5, INT32 tmp12)
{
  for (ctr = 8 - 1; ctr >= 0; ctr--)
    {
      tmp0 = dataptr[8 * 0] + wsptr[8 * 6];
      tmp1 = dataptr[8 * 1] + wsptr[8 * 5];
      tmp2 = dataptr[8 * 2] + wsptr[8 * 4];
      tmp3 = dataptr[8 * 3] + wsptr[8 * 3];
      tmp4 = dataptr[8 * 4] + wsptr[8 * 2];
      tmp5 = dataptr[8 * 5] + wsptr[8 * 1];
      tmp6 = dataptr[8 * 6] + wsptr[8 * 0];
      tmp7 = dataptr[8 * 7];
      tmp10 = dataptr[8 * 0] - wsptr[8 * 6];
      tmp11 = dataptr[8 * 1] - wsptr[8 * 5];
      tmp12 = dataptr[8 * 2] - wsptr[8 * 4];
      tmp13 = dataptr[8 * 3] - wsptr[8 * 3];
      tmp14 = dataptr[8 * 4] - wsptr[8 * 2];
      tmp15 = dataptr[8 * 5] - wsptr[8 * 1];
      tmp16 = dataptr[8 * 6] - wsptr[8 * 0];
      z1 = tmp0 + tmp4 + tmp5;
      z2 = tmp1 + tmp3 + tmp6;
      z3 = tmp2 + tmp7;
      dataptr[8 * 0] =
	(DCTELEM) (((((z1 + z2 +
		       z3) *
		      (((INT32)
			((1.137777778) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      z3 += z3;
      dataptr[8 * 6] =
	(DCTELEM) (((((z1 -
		       z3) *
		      (((INT32) ((1.301757503) * (((INT32) 1) << 13) + 0.5))))
		     -
		     ((z2 -
		       z3) *
		      (((INT32)
			((0.497227121) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      tmp2 += ((tmp1 + tmp4) >> 1) - tmp7 - tmp7;
      z1 =
	((tmp3 -
	  tmp2) * (((INT32) ((1.742091575) * (((INT32) 1) << 13) + 0.5)))) -
	((tmp6 -
	  tmp2) * (((INT32) ((2.546621957) * (((INT32) 1) << 13) + 0.5))));
      z2 =
	((tmp5 -
	  tmp2) * (((INT32) ((0.908479156) * (((INT32) 1) << 13) + 0.5)))) -
	((tmp0 -
	  tmp2) * (((INT32) ((0.103948774) * (((INT32) 1) << 13) + 0.5))));
      z3 =
	((tmp0 -
	  tmp3) * (((INT32) ((1.573898926) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp6 -
	  tmp5) * (((INT32) ((1.076671805) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp1 -
	  tmp4) * (((INT32) ((0.899492312) * (((INT32) 1) << 13) + 0.5))));
      dataptr[8 * 2] =
	(DCTELEM) (((z1 + z3) + (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr[8 * 4] =
	(DCTELEM) (((z2 + z3) + (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      tmp2 =
	((tmp10 - tmp12 - tmp13 + tmp15 +
	  tmp16) * (((INT32) ((1.393487498) * (((INT32) 1) << 13) + 0.5))));
      tmp1 =
	((tmp10 - tmp14 -
	  tmp15) * (((INT32) ((1.530307725) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp11 - tmp13 -
	  tmp16) * (((INT32) ((0.945782187) * (((INT32) 1) << 13) + 0.5))));
      tmp12 =
	((tmp12) * (((INT32) ((1.393487498) * (((INT32) 1) << 13) + 0.5))));
      tmp4 =
	((tmp10 -
	  tmp16) * (((INT32) ((1.600246161) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp11 +
	  tmp14) * (((INT32) ((1.530307725) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp13 +
	  tmp15) * (((INT32) ((0.654463974) * (((INT32) 1) << 13) + 0.5))));
      tmp0 =
	((tmp13) * (((INT32) ((0.541301207) * (((INT32) 1) << 13) + 0.5)))) -
	((tmp14) * (((INT32) ((0.584525538) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp16) * (((INT32) ((1.934788705) * (((INT32) 1) << 13) + 0.5)))) +
	tmp4 + tmp12;
      tmp3 =
	((tmp10) * (-((INT32) ((0.404480980) * (((INT32) 1) << 13) + 0.5)))) -
	((tmp11) * (((INT32) ((2.476089912) * (((INT32) 1) << 13) + 0.5)))) -
	((tmp15) * (((INT32) ((0.989006518) * (((INT32) 1) << 13) + 0.5)))) +
	tmp4 - tmp12;
      dataptr[8 * 1] =
	(DCTELEM) (((tmp0) + (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr[8 * 3] =
	(DCTELEM) (((tmp1) + (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr[8 * 5] =
	(DCTELEM) (((tmp2) + (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr[8 * 7] =
	(DCTELEM) (((tmp3) + (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr++;
      wsptr++;
    }
}

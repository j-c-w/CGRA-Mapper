// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJPEG/jfdctint.c

#include <stdint.h>
#include <stdio.h>




typedef long INT32;
typedef int DCTELEM;

int
fn (INT32 tmp4, INT32 tmp7, DCTELEM * dataptr, INT32 tmp15, INT32 tmp11,
    INT32 tmp1, int ctr, INT32 tmp16, INT32 tmp17, INT32 tmp6, INT32 tmp3,
    INT32 tmp0, INT32 tmp13, INT32 tmp10, INT32 tmp2, DCTELEM * wsptr,
    INT32 tmp14, INT32 tmp5, INT32 tmp12)
{
  for (ctr = 8 - 1; ctr >= 0; ctr--)
    {
      tmp0 = dataptr[8 * 0] + wsptr[8 * 7];
      tmp1 = dataptr[8 * 1] + wsptr[8 * 6];
      tmp2 = dataptr[8 * 2] + wsptr[8 * 5];
      tmp3 = dataptr[8 * 3] + wsptr[8 * 4];
      tmp4 = dataptr[8 * 4] + wsptr[8 * 3];
      tmp5 = dataptr[8 * 5] + wsptr[8 * 2];
      tmp6 = dataptr[8 * 6] + wsptr[8 * 1];
      tmp7 = dataptr[8 * 7] + wsptr[8 * 0];
      tmp10 = tmp0 + tmp7;
      tmp14 = tmp0 - tmp7;
      tmp11 = tmp1 + tmp6;
      tmp15 = tmp1 - tmp6;
      tmp12 = tmp2 + tmp5;
      tmp16 = tmp2 - tmp5;
      tmp13 = tmp3 + tmp4;
      tmp17 = tmp3 - tmp4;
      tmp0 = dataptr[8 * 0] - wsptr[8 * 7];
      tmp1 = dataptr[8 * 1] - wsptr[8 * 6];
      tmp2 = dataptr[8 * 2] - wsptr[8 * 5];
      tmp3 = dataptr[8 * 3] - wsptr[8 * 4];
      tmp4 = dataptr[8 * 4] - wsptr[8 * 3];
      tmp5 = dataptr[8 * 5] - wsptr[8 * 2];
      tmp6 = dataptr[8 * 6] - wsptr[8 * 1];
      tmp7 = dataptr[8 * 7] - wsptr[8 * 0];
      dataptr[8 * 0] =
	(DCTELEM) (((tmp10 + tmp11 + tmp12 + tmp13) +
		    (((INT32) 1) << ((2 + 1) - 1))) >> (2 + 1));
      dataptr[8 * 4] =
	(DCTELEM) (((((tmp10 -
		       tmp13) *
		      (((INT32) ((1.306562965) * (((INT32) 1) << 13) + 0.5))))
		     + ((tmp11 - tmp12) * (((INT32) 4433)))) +
		    (((INT32) 1) << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
      tmp10 =
	((tmp17 -
	  tmp15) * (((INT32) ((0.275899379) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp14 -
	  tmp16) * (((INT32) ((1.387039845) * (((INT32) 1) << 13) + 0.5))));
      dataptr[8 * 2] =
	(DCTELEM) (((tmp10 +
		     ((tmp15) *
		      (((INT32) ((1.451774982) * (((INT32) 1) << 13) + 0.5))))
		     +
		     ((tmp16) *
		      (((INT32)
			((2.172734804) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
      dataptr[8 * 6] =
	(DCTELEM) (((tmp10 -
		     ((tmp14) *
		      (((INT32) ((0.211164243) * (((INT32) 1) << 13) + 0.5))))
		     -
		     ((tmp17) *
		      (((INT32)
			((1.061594338) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
      tmp11 =
	((tmp0 +
	  tmp1) * (((INT32) ((1.353318001) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp6 -
	  tmp7) * (((INT32) ((0.410524528) * (((INT32) 1) << 13) + 0.5))));
      tmp12 =
	((tmp0 +
	  tmp2) * (((INT32) ((1.247225013) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp5 +
	  tmp7) * (((INT32) ((0.666655658) * (((INT32) 1) << 13) + 0.5))));
      tmp13 =
	((tmp0 +
	  tmp3) * (((INT32) ((1.093201867) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp4 -
	  tmp7) * (((INT32) ((0.897167586) * (((INT32) 1) << 13) + 0.5))));
      tmp14 =
	((tmp1 +
	  tmp2) * (((INT32) ((0.138617169) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp6 -
	  tmp5) * (((INT32) ((1.407403738) * (((INT32) 1) << 13) + 0.5))));
      tmp15 =
	((tmp1 +
	  tmp3) * (-((INT32) ((0.666655658) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp4 +
	  tmp6) * (-((INT32) ((1.247225013) * (((INT32) 1) << 13) + 0.5))));
      tmp16 =
	((tmp2 +
	  tmp3) * (-((INT32) ((1.353318001) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp5 -
	  tmp4) * (((INT32) ((0.410524528) * (((INT32) 1) << 13) + 0.5))));
      tmp10 =
	tmp11 + tmp12 + tmp13 -
	((tmp0) * (((INT32) ((2.286341144) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp7) * (((INT32) ((0.779653625) * (((INT32) 1) << 13) + 0.5))));
      tmp11 +=
	tmp14 + tmp15 +
	((tmp1) * (((INT32) ((0.071888074) * (((INT32) 1) << 13) + 0.5)))) -
	((tmp6) * (((INT32) ((1.663905119) * (((INT32) 1) << 13) + 0.5))));
      tmp12 +=
	tmp14 + tmp16 -
	((tmp2) * (((INT32) ((1.125726048) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp5) * (((INT32) ((1.227391138) * (((INT32) 1) << 13) + 0.5))));
      tmp13 +=
	tmp15 + tmp16 +
	((tmp3) * (((INT32) ((1.065388962) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp4) * (((INT32) ((2.167985692) * (((INT32) 1) << 13) + 0.5))));
      dataptr[8 * 1] =
	(DCTELEM) (((tmp10) + (((INT32) 1) << ((13 + 2 + 1) - 1))) >> (13 +
								       2 +
								       1));
      dataptr[8 * 3] =
	(DCTELEM) (((tmp11) + (((INT32) 1) << ((13 + 2 + 1) - 1))) >> (13 +
								       2 +
								       1));
      dataptr[8 * 5] =
	(DCTELEM) (((tmp12) + (((INT32) 1) << ((13 + 2 + 1) - 1))) >> (13 +
								       2 +
								       1));
      dataptr[8 * 7] =
	(DCTELEM) (((tmp13) + (((INT32) 1) << ((13 + 2 + 1) - 1))) >> (13 +
								       2 +
								       1));
      dataptr++;
      wsptr++;
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJPEG/jfdctint.c

#include <stdint.h>
#include <stdio.h>




typedef long INT32;
typedef int DCTELEM;

int
fn (INT32 tmp16, INT32 tmp2, DCTELEM * wsptr, INT32 tmp14, INT32 tmp5,
    INT32 tmp4, INT32 tmp11, INT32 tmp15, INT32 tmp6, INT32 tmp0, INT32 tmp12,
    INT32 tmp3, INT32 tmp13, INT32 tmp1, DCTELEM * dataptr, int ctr,
    INT32 tmp10)
{
  for (ctr = 8 - 1; ctr >= 0; ctr--)
    {
      tmp0 = dataptr[8 * 0] + wsptr[8 * 5];
      tmp1 = dataptr[8 * 1] + wsptr[8 * 4];
      tmp2 = dataptr[8 * 2] + wsptr[8 * 3];
      tmp13 = dataptr[8 * 3] + wsptr[8 * 2];
      tmp4 = dataptr[8 * 4] + wsptr[8 * 1];
      tmp5 = dataptr[8 * 5] + wsptr[8 * 0];
      tmp6 = dataptr[8 * 6] + dataptr[8 * 7];
      tmp10 = tmp0 + tmp6;
      tmp14 = tmp0 - tmp6;
      tmp11 = tmp1 + tmp5;
      tmp15 = tmp1 - tmp5;
      tmp12 = tmp2 + tmp4;
      tmp16 = tmp2 - tmp4;
      tmp0 = dataptr[8 * 0] - wsptr[8 * 5];
      tmp1 = dataptr[8 * 1] - wsptr[8 * 4];
      tmp2 = dataptr[8 * 2] - wsptr[8 * 3];
      tmp3 = dataptr[8 * 3] - wsptr[8 * 2];
      tmp4 = dataptr[8 * 4] - wsptr[8 * 1];
      tmp5 = dataptr[8 * 5] - wsptr[8 * 0];
      tmp6 = dataptr[8 * 6] - dataptr[8 * 7];
      dataptr[8 * 0] =
	(DCTELEM) (((((tmp10 + tmp11 + tmp12 +
		       tmp13) *
		      (((INT32)
			((0.653061224) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 1) - 1))) >> (13 + 1));
      tmp13 += tmp13;
      dataptr[8 * 4] =
	(DCTELEM) (((((tmp10 -
		       tmp13) *
		      (((INT32) ((0.832106052) * (((INT32) 1) << 13) + 0.5))))
		     +
		     ((tmp11 -
		       tmp13) *
		      (((INT32) ((0.205513223) * (((INT32) 1) << 13) + 0.5))))
		     -
		     ((tmp12 -
		       tmp13) *
		      (((INT32)
			((0.575835255) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 1) - 1))) >> (13 + 1));
      tmp10 =
	((tmp14 +
	  tmp15) * (((INT32) ((0.722074570) * (((INT32) 1) << 13) + 0.5))));
      dataptr[8 * 2] =
	(DCTELEM) (((tmp10 +
		     ((tmp14) *
		      (((INT32) ((0.178337691) * (((INT32) 1) << 13) + 0.5))))
		     +
		     ((tmp16) *
		      (((INT32)
			((0.400721155) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 1) - 1))) >> (13 + 1));
      dataptr[8 * 6] =
	(DCTELEM) (((tmp10 -
		     ((tmp15) *
		      (((INT32) ((1.122795725) * (((INT32) 1) << 13) + 0.5))))
		     -
		     ((tmp16) *
		      (((INT32)
			((0.900412262) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 1) - 1))) >> (13 + 1));
      tmp10 = tmp1 + tmp2;
      tmp11 = tmp5 - tmp4;
      dataptr[8 * 7] =
	(DCTELEM) (((((tmp0 - tmp10 + tmp3 - tmp11 -
		       tmp6) *
		      (((INT32)
			((0.653061224) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 1) - 1))) >> (13 + 1));
      tmp3 =
	((tmp3) * (((INT32) ((0.653061224) * (((INT32) 1) << 13) + 0.5))));
      tmp10 =
	((tmp10) * (-((INT32) ((0.103406812) * (((INT32) 1) << 13) + 0.5))));
      tmp11 =
	((tmp11) * (((INT32) ((0.917760839) * (((INT32) 1) << 13) + 0.5))));
      tmp10 += tmp11 - tmp3;
      tmp11 =
	((tmp0 +
	  tmp2) * (((INT32) ((0.782007410) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp4 +
	  tmp6) * (((INT32) ((0.491367823) * (((INT32) 1) << 13) + 0.5))));
      dataptr[8 * 5] =
	(DCTELEM) (((tmp10 + tmp11 -
		     ((tmp2) *
		      (((INT32) ((1.550341076) * (((INT32) 1) << 13) + 0.5))))
		     +
		     ((tmp4) *
		      (((INT32)
			((0.731428202) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 1) - 1))) >> (13 + 1));
      tmp12 =
	((tmp0 +
	  tmp1) * (((INT32) ((0.871740478) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp5 -
	  tmp6) * (((INT32) ((0.305035186) * (((INT32) 1) << 13) + 0.5))));
      dataptr[8 * 3] =
	(DCTELEM) (((tmp10 + tmp12 -
		     ((tmp1) *
		      (((INT32) ((0.276965844) * (((INT32) 1) << 13) + 0.5))))
		     -
		     ((tmp5) *
		      (((INT32)
			((2.004803435) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 1) - 1))) >> (13 + 1));
      dataptr[8 * 1] =
	(DCTELEM) (((tmp11 + tmp12 + tmp3 -
		     ((tmp0) *
		      (((INT32) ((0.735987049) * (((INT32) 1) << 13) + 0.5))))
		     -
		     ((tmp6) *
		      (((INT32)
			((0.082925825) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 1) - 1))) >> (13 + 1));
      dataptr++;
      wsptr++;
    }
}

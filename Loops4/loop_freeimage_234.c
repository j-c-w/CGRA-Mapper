// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJPEG/jfdctint.c

#include <stdint.h>
#include <stdio.h>




typedef int DCTELEM;
typedef long INT32;

int
fn (INT32 tmp2, DCTELEM * wsptr, INT32 z3, INT32 tmp14, INT32 tmp5,
    INT32 tmp4, INT32 z1, INT32 tmp11, INT32 tmp3, INT32 tmp12, INT32 tmp0,
    INT32 tmp13, INT32 z2, INT32 tmp1, DCTELEM * dataptr, int ctr,
    INT32 tmp10)
{
  for (ctr = 8 - 1; ctr >= 0; ctr--)
    {
      tmp0 = dataptr[8 * 0] + wsptr[8 * 2];
      tmp1 = dataptr[8 * 1] + wsptr[8 * 1];
      tmp2 = dataptr[8 * 2] + wsptr[8 * 0];
      tmp3 = dataptr[8 * 3] + dataptr[8 * 7];
      tmp4 = dataptr[8 * 4] + dataptr[8 * 6];
      tmp5 = dataptr[8 * 5];
      tmp10 = dataptr[8 * 0] - wsptr[8 * 2];
      tmp11 = dataptr[8 * 1] - wsptr[8 * 1];
      tmp12 = dataptr[8 * 2] - wsptr[8 * 0];
      tmp13 = dataptr[8 * 3] - dataptr[8 * 7];
      tmp14 = dataptr[8 * 4] - dataptr[8 * 6];
      dataptr[8 * 0] =
	(DCTELEM) (((((tmp0 + tmp1 + tmp2 + tmp3 + tmp4 +
		       tmp5) *
		      (((INT32)
			((1.057851240) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      tmp5 += tmp5;
      tmp0 -= tmp5;
      tmp1 -= tmp5;
      tmp2 -= tmp5;
      tmp3 -= tmp5;
      tmp4 -= tmp5;
      z1 =
	((tmp0 +
	  tmp3) * (((INT32) ((1.435427942) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp2 +
	  tmp4) * (((INT32) ((0.212906922) * (((INT32) 1) << 13) + 0.5))));
      z2 =
	((tmp1 -
	  tmp3) * (((INT32) ((0.979689713) * (((INT32) 1) << 13) + 0.5))));
      z3 =
	((tmp0 -
	  tmp1) * (((INT32) ((1.258538479) * (((INT32) 1) << 13) + 0.5))));
      dataptr[8 * 2] =
	(DCTELEM) (((z1 + z2 -
		     ((tmp3) *
		      (((INT32) ((1.077210542) * (((INT32) 1) << 13) + 0.5))))
		     -
		     ((tmp4) *
		      (((INT32)
			((1.471445400) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr[8 * 4] =
	(DCTELEM) (((z2 + z3 +
		     ((tmp1) *
		      (((INT32) ((0.065941844) * (((INT32) 1) << 13) + 0.5))))
		     -
		     ((tmp2) *
		      (((INT32) ((1.435427942) * (((INT32) 1) << 13) + 0.5))))
		     +
		     ((tmp4) *
		      (((INT32)
			((0.621472312) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr[8 * 6] =
	(DCTELEM) (((z1 + z3 -
		     ((tmp0) *
		      (((INT32) ((1.714276708) * (((INT32) 1) << 13) + 0.5))))
		     -
		     ((tmp2) *
		      (((INT32)
			((0.834379234) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      tmp1 =
	((tmp10 +
	  tmp11) * (((INT32) ((1.360834544) * (((INT32) 1) << 13) + 0.5))));
      tmp2 =
	((tmp10 +
	  tmp12) * (((INT32) ((1.130622199) * (((INT32) 1) << 13) + 0.5))));
      tmp3 =
	((tmp10 +
	  tmp13) * (((INT32) ((0.808813568) * (((INT32) 1) << 13) + 0.5))));
      tmp0 =
	tmp1 + tmp2 + tmp3 -
	((tmp10) * (((INT32) ((1.819470145) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp14) * (((INT32) ((0.421479672) * (((INT32) 1) << 13) + 0.5))));
      tmp4 =
	((tmp11 +
	  tmp12) * (-((INT32) ((0.808813568) * (((INT32) 1) << 13) + 0.5))));
      tmp5 =
	((tmp11 +
	  tmp13) * (-((INT32) ((1.480800167) * (((INT32) 1) << 13) + 0.5))));
      tmp1 +=
	tmp4 + tmp5 +
	((tmp11) * (((INT32) ((1.350258864) * (((INT32) 1) << 13) + 0.5)))) -
	((tmp14) * (((INT32) ((1.130622199) * (((INT32) 1) << 13) + 0.5))));
      tmp10 =
	((tmp12 +
	  tmp13) * (((INT32) ((0.421479672) * (((INT32) 1) << 13) + 0.5))));
      tmp2 +=
	tmp4 + tmp10 -
	((tmp12) * (((INT32) ((2.104122847) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp14) * (((INT32) ((1.480800167) * (((INT32) 1) << 13) + 0.5))));
      tmp3 +=
	tmp5 + tmp10 +
	((tmp13) * (((INT32) ((1.381129125) * (((INT32) 1) << 13) + 0.5)))) -
	((tmp14) * (((INT32) ((1.360834544) * (((INT32) 1) << 13) + 0.5))));
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

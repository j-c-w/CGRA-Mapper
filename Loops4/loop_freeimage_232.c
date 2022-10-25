// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJPEG/jfdctint.c

#include <stdint.h>
#include <stdio.h>




typedef int DCTELEM;
typedef long INT32;

int
fn (INT32 tmp2, DCTELEM * wsptr, INT32 tmp4, INT32 tmp11, INT32 z1,
    INT32 tmp3, INT32 tmp12, INT32 tmp0, INT32 tmp13, INT32 z2, INT32 tmp1,
    DCTELEM * dataptr, int ctr, INT32 tmp10)
{
  for (ctr = 8 - 1; ctr >= 0; ctr--)
    {
      tmp0 = dataptr[8 * 0] + wsptr[8 * 0];
      tmp1 = dataptr[8 * 1] + dataptr[8 * 7];
      tmp2 = dataptr[8 * 2] + dataptr[8 * 6];
      tmp3 = dataptr[8 * 3] + dataptr[8 * 5];
      tmp4 = dataptr[8 * 4];
      tmp10 = dataptr[8 * 0] - wsptr[8 * 0];
      tmp11 = dataptr[8 * 1] - dataptr[8 * 7];
      tmp12 = dataptr[8 * 2] - dataptr[8 * 6];
      tmp13 = dataptr[8 * 3] - dataptr[8 * 5];
      z1 = tmp0 + tmp2 + tmp3;
      z2 = tmp1 + tmp4;
      dataptr[8 * 0] =
	(DCTELEM) (((((z1 +
		       z2) *
		      (((INT32)
			((1.580246914) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr[8 * 6] =
	(DCTELEM) (((((z1 - z2 -
		       z2) *
		      (((INT32)
			((1.117403309) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      z1 =
	((tmp0 -
	  tmp2) * (((INT32) ((2.100031287) * (((INT32) 1) << 13) + 0.5))));
      z2 =
	((tmp1 - tmp4 -
	  tmp4) * (((INT32) ((1.117403309) * (((INT32) 1) << 13) + 0.5))));
      dataptr[8 * 2] =
	(DCTELEM) (((((tmp2 -
		       tmp3) *
		      (((INT32) ((1.711961190) * (((INT32) 1) << 13) + 0.5))))
		     + z1 + z2) + (((INT32) 1) << ((13 + 2) - 1))) >> (13 +
								       2));
      dataptr[8 * 4] =
	(DCTELEM) (((((tmp3 -
		       tmp0) *
		      (((INT32) ((0.388070096) * (((INT32) 1) << 13) + 0.5))))
		     + z1 - z2) + (((INT32) 1) << ((13 + 2) - 1))) >> (13 +
								       2));
      dataptr[8 * 3] =
	(DCTELEM) (((((tmp10 - tmp12 -
		       tmp13) *
		      (((INT32)
			((1.935399303) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      tmp11 =
	((tmp11) * (((INT32) ((1.935399303) * (((INT32) 1) << 13) + 0.5))));
      tmp0 =
	((tmp10 +
	  tmp12) * (((INT32) ((1.436506004) * (((INT32) 1) << 13) + 0.5))));
      tmp1 =
	((tmp10 +
	  tmp13) * (((INT32) ((0.764348879) * (((INT32) 1) << 13) + 0.5))));
      dataptr[8 * 1] =
	(DCTELEM) (((tmp11 + tmp0 + tmp1) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      tmp2 =
	((tmp12 -
	  tmp13) * (((INT32) ((2.200854883) * (((INT32) 1) << 13) + 0.5))));
      dataptr[8 * 5] =
	(DCTELEM) (((tmp0 - tmp11 - tmp2) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr[8 * 7] =
	(DCTELEM) (((tmp1 - tmp11 + tmp2) +
		    (((INT32) 1) << ((13 + 2) - 1))) >> (13 + 2));
      dataptr++;
      wsptr++;
    }
}

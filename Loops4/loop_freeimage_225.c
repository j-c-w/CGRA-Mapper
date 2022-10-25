// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJPEG/jfdctint.c

#include <stdint.h>
#include <stdio.h>




typedef long INT32;
typedef int DCTELEM;

int
fn (INT32 tmp2, INT32 z3, INT32 z1, INT32 tmp11, INT32 tmp3, INT32 tmp12,
    INT32 tmp0, INT32 z2, INT32 tmp1, DCTELEM * dataptr, int ctr, INT32 tmp10)
{
  for (ctr = 8 - 1; ctr >= 0; ctr--)
    {
      tmp0 = dataptr[8 * 0] + dataptr[8 * 6];
      tmp1 = dataptr[8 * 1] + dataptr[8 * 5];
      tmp2 = dataptr[8 * 2] + dataptr[8 * 4];
      tmp3 = dataptr[8 * 3];
      tmp10 = dataptr[8 * 0] - dataptr[8 * 6];
      tmp11 = dataptr[8 * 1] - dataptr[8 * 5];
      tmp12 = dataptr[8 * 2] - dataptr[8 * 4];
      z1 = tmp0 + tmp2;
      dataptr[8 * 0] =
	(DCTELEM) (((((z1 + tmp1 +
		       tmp3) *
		      (((INT32)
			((1.306122449) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
      tmp3 += tmp3;
      z1 -= tmp3;
      z1 -= tmp3;
      z1 = ((z1) * (((INT32) ((0.461784020) * (((INT32) 1) << 13) + 0.5))));
      z2 =
	((tmp0 -
	  tmp2) * (((INT32) ((1.202428084) * (((INT32) 1) << 13) + 0.5))));
      z3 =
	((tmp1 -
	  tmp2) * (((INT32) ((0.411026446) * (((INT32) 1) << 13) + 0.5))));
      dataptr[8 * 2] =
	(DCTELEM) (((z1 + z2 + z3) +
		    (((INT32) 1) << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
      z1 -= z2;
      z2 =
	((tmp0 -
	  tmp1) * (((INT32) ((1.151670509) * (((INT32) 1) << 13) + 0.5))));
      dataptr[8 * 4] =
	(DCTELEM) (((z2 + z3 -
		     ((tmp1 -
		       tmp3) *
		      (((INT32)
			((0.923568041) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 2 + 1) - 1))) >> (13 + 2 + 1));
      dataptr[8 * 6] =
	(DCTELEM) (((z1 + z2) + (((INT32) 1) << ((13 + 2 + 1) - 1))) >> (13 +
									 2 +
									 1));
      tmp1 =
	((tmp10 +
	  tmp11) * (((INT32) ((1.221765677) * (((INT32) 1) << 13) + 0.5))));
      tmp2 =
	((tmp10 -
	  tmp11) * (((INT32) ((0.222383464) * (((INT32) 1) << 13) + 0.5))));
      tmp0 = tmp1 - tmp2;
      tmp1 += tmp2;
      tmp2 =
	((tmp11 +
	  tmp12) * (-((INT32) ((1.800824523) * (((INT32) 1) << 13) + 0.5))));
      tmp1 += tmp2;
      tmp3 =
	((tmp10 +
	  tmp12) * (((INT32) ((0.801442310) * (((INT32) 1) << 13) + 0.5))));
      tmp0 += tmp3;
      tmp2 +=
	tmp3 +
	((tmp12) * (((INT32) ((2.443531355) * (((INT32) 1) << 13) + 0.5))));
      dataptr[8 * 1] =
	(DCTELEM) (((tmp0) + (((INT32) 1) << ((13 + 2 + 1) - 1))) >> (13 + 2 +
								      1));
      dataptr[8 * 3] =
	(DCTELEM) (((tmp1) + (((INT32) 1) << ((13 + 2 + 1) - 1))) >> (13 + 2 +
								      1));
      dataptr[8 * 5] =
	(DCTELEM) (((tmp2) + (((INT32) 1) << ((13 + 2 + 1) - 1))) >> (13 + 2 +
								      1));
      dataptr++;
    }
}

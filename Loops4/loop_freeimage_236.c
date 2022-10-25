// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJPEG/jfdctint.c

#include <stdint.h>
#include <stdio.h>




typedef long INT32;
typedef int DCTELEM;

int
fn (INT32 tmp2, DCTELEM * wsptr, INT32 tmp14, INT32 tmp5, INT32 tmp15,
    INT32 tmp11, INT32 z1, INT32 tmp6, INT32 tmp3, INT32 tmp4, INT32 tmp0,
    INT32 tmp12, INT32 tmp13, INT32 z2, INT32 tmp1, DCTELEM * dataptr,
    int ctr, INT32 tmp10)
{
  for (ctr = 8 - 1; ctr >= 0; ctr--)
    {
      tmp0 = dataptr[8 * 0] + wsptr[8 * 4];
      tmp1 = dataptr[8 * 1] + wsptr[8 * 3];
      tmp2 = dataptr[8 * 2] + wsptr[8 * 2];
      tmp3 = dataptr[8 * 3] + wsptr[8 * 1];
      tmp4 = dataptr[8 * 4] + wsptr[8 * 0];
      tmp5 = dataptr[8 * 5] + dataptr[8 * 7];
      tmp6 = dataptr[8 * 6];
      tmp10 = dataptr[8 * 0] - wsptr[8 * 4];
      tmp11 = dataptr[8 * 1] - wsptr[8 * 3];
      tmp12 = dataptr[8 * 2] - wsptr[8 * 2];
      tmp13 = dataptr[8 * 3] - wsptr[8 * 1];
      tmp14 = dataptr[8 * 4] - wsptr[8 * 0];
      tmp15 = dataptr[8 * 5] - dataptr[8 * 7];
      dataptr[8 * 0] =
	(DCTELEM) (((((tmp0 + tmp1 + tmp2 + tmp3 + tmp4 + tmp5 +
		       tmp6) *
		      (((INT32)
			((0.757396450) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 1) - 1))) >> (13 + 1));
      tmp6 += tmp6;
      tmp0 -= tmp6;
      tmp1 -= tmp6;
      tmp2 -= tmp6;
      tmp3 -= tmp6;
      tmp4 -= tmp6;
      tmp5 -= tmp6;
      dataptr[8 * 2] =
	(DCTELEM) (((((tmp0) *
		      (((INT32) ((1.039995521) * (((INT32) 1) << 13) + 0.5))))
		     +
		     ((tmp1) *
		      (((INT32) ((0.801745081) * (((INT32) 1) << 13) + 0.5))))
		     +
		     ((tmp2) *
		      (((INT32) ((0.379824504) * (((INT32) 1) << 13) + 0.5))))
		     -
		     ((tmp3) *
		      (((INT32) ((0.129109289) * (((INT32) 1) << 13) + 0.5))))
		     -
		     ((tmp4) *
		      (((INT32) ((0.608465700) * (((INT32) 1) << 13) + 0.5))))
		     -
		     ((tmp5) *
		      (((INT32)
			((0.948429952) * (((INT32) 1) << 13) + 0.5))))) +
		    (((INT32) 1) << ((13 + 1) - 1))) >> (13 + 1));
      z1 =
	((tmp0 -
	  tmp2) * (((INT32) ((0.875087516) * (((INT32) 1) << 13) + 0.5)))) -
	((tmp3 -
	  tmp4) * (((INT32) ((0.330085509) * (((INT32) 1) << 13) + 0.5)))) -
	((tmp1 -
	  tmp5) * (((INT32) ((0.239678205) * (((INT32) 1) << 13) + 0.5))));
      z2 =
	((tmp0 +
	  tmp2) * (((INT32) ((0.073342435) * (((INT32) 1) << 13) + 0.5)))) -
	((tmp3 +
	  tmp4) * (((INT32) ((0.709910013) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp1 +
	  tmp5) * (((INT32) ((0.368787494) * (((INT32) 1) << 13) + 0.5))));
      dataptr[8 * 4] =
	(DCTELEM) (((z1 + z2) + (((INT32) 1) << ((13 + 1) - 1))) >> (13 + 1));
      dataptr[8 * 6] =
	(DCTELEM) (((z1 - z2) + (((INT32) 1) << ((13 + 1) - 1))) >> (13 + 1));
      tmp1 =
	((tmp10 +
	  tmp11) * (((INT32) ((1.001514908) * (((INT32) 1) << 13) + 0.5))));
      tmp2 =
	((tmp10 +
	  tmp12) * (((INT32) ((0.881514751) * (((INT32) 1) << 13) + 0.5))));
      tmp3 =
	((tmp10 +
	  tmp13) * (((INT32) ((0.710284161) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp14 +
	  tmp15) * (((INT32) ((0.256335874) * (((INT32) 1) << 13) + 0.5))));
      tmp0 =
	tmp1 + tmp2 + tmp3 -
	((tmp10) * (((INT32) ((1.530003162) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp14) * (((INT32) ((0.241438564) * (((INT32) 1) << 13) + 0.5))));
      tmp4 =
	((tmp14 -
	  tmp15) * (((INT32) ((0.710284161) * (((INT32) 1) << 13) + 0.5)))) -
	((tmp11 +
	  tmp12) * (((INT32) ((0.256335874) * (((INT32) 1) << 13) + 0.5))));
      tmp5 =
	((tmp11 +
	  tmp13) * (-((INT32) ((0.881514751) * (((INT32) 1) << 13) + 0.5))));
      tmp1 +=
	tmp4 + tmp5 +
	((tmp11) * (((INT32) ((0.634110155) * (((INT32) 1) << 13) + 0.5)))) -
	((tmp14) * (((INT32) ((1.773594819) * (((INT32) 1) << 13) + 0.5))));
      tmp6 =
	((tmp12 +
	  tmp13) * (-((INT32) ((0.497774438) * (((INT32) 1) << 13) + 0.5))));
      tmp2 +=
	tmp4 + tmp6 -
	((tmp12) * (((INT32) ((1.190715098) * (((INT32) 1) << 13) + 0.5)))) +
	((tmp15) * (((INT32) ((1.711799069) * (((INT32) 1) << 13) + 0.5))));
      tmp3 +=
	tmp5 + tmp6 +
	((tmp13) * (((INT32) ((1.670519935) * (((INT32) 1) << 13) + 0.5)))) -
	((tmp15) * (((INT32) ((1.319646532) * (((INT32) 1) << 13) + 0.5))));
      dataptr[8 * 1] =
	(DCTELEM) (((tmp0) + (((INT32) 1) << ((13 + 1) - 1))) >> (13 + 1));
      dataptr[8 * 3] =
	(DCTELEM) (((tmp1) + (((INT32) 1) << ((13 + 1) - 1))) >> (13 + 1));
      dataptr[8 * 5] =
	(DCTELEM) (((tmp2) + (((INT32) 1) << ((13 + 1) - 1))) >> (13 + 1));
      dataptr[8 * 7] =
	(DCTELEM) (((tmp3) + (((INT32) 1) << ((13 + 1) - 1))) >> (13 + 1));
      dataptr++;
      wsptr++;
    }
}

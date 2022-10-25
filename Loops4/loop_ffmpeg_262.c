// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/j2kenc.c

#include <stdint.h>
#include <stdio.h>






int
fn (int lut_nmsedec_sig0[128], int i, int mask, int lut_nmsedec_ref0[128],
    int lut_nmsedec_ref[128], int a, int lut_nmsedec_sig[128])
{
  for (i = 0; i < (1 << 7); i++)
    {
      lut_nmsedec_sig[i] =
	(((3 * i << (13 - (7 - 1))) - (9 << 11)) >
	 (0) ? ((3 * i << (13 - (7 - 1))) - (9 << 11)) : (0));
      lut_nmsedec_sig0[i] =
	(((i * i + (1 << (7 - 1) - 1) & mask) << 1) >
	 (0) ? ((i * i + (1 << (7 - 1) - 1) & mask) << 1) : (0));
      a = (i >> (7 - 2) & 2) + 1;
      lut_nmsedec_ref[i] =
	(((a - 2) * (i << (13 - (7 - 1))) + (1 << 13) - (a * a << 11)) >
	 (0) ? ((a - 2) * (i << (13 - (7 - 1))) + (1 << 13) -
		(a * a << 11)) : (0));
      lut_nmsedec_ref0[i] =
	((((i * i - (i << 7) + (1 << 2 * (7 - 1)) +
	    (1 << ((7 - 1) - 1))) & mask) << 1) >
	 (0)
	 ? (((i * i - (i << 7) + (1 << 2 * (7 - 1)) +
	      (1 << ((7 - 1) - 1))) & mask) << 1) : (0));
    }
}

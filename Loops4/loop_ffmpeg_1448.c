// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/aacpsdsp_float.c

#include <stdint.h>
#include <stdio.h>




typedef float UINTFLOAT;
typedef float INTFLOAT;

int
fn (INTFLOAT h02, INTFLOAT h01, INTFLOAT (*l)[2], INTFLOAT h13,
    UINTFLOAT hs02, INTFLOAT (*r)[2], UINTFLOAT hs10, int len, INTFLOAT h12,
    UINTFLOAT hs01, INTFLOAT h03, UINTFLOAT hs00, INTFLOAT h10,
    UINTFLOAT hs11, UINTFLOAT hs03, INTFLOAT h00, INTFLOAT h11, int n,
    UINTFLOAT hs13, UINTFLOAT hs12)
{
  for (n = 0; n < len; n++)
    {
      INTFLOAT l_re = l[n][0];
      INTFLOAT l_im = l[n][1];
      INTFLOAT r_re = r[n][0];
      INTFLOAT r_im = r[n][1];
      h00 += hs00;
      h01 += hs01;
      h02 += hs02;
      h03 += hs03;
      h10 += hs10;
      h11 += hs11;
      h12 += hs12;
      h13 += hs13;
      l[n][0] =
	((h00) * (l_re) + (h02) * (r_re) - (h10) * (l_im) - (h12) * (r_im));
      l[n][1] =
	((h00) * (l_im) + (h02) * (r_im) + (h10) * (l_re) + (h12) * (r_re));
      r[n][0] =
	((h01) * (l_re) + (h03) * (r_re) - (h11) * (l_im) - (h13) * (r_im));
      r[n][1] =
	((h01) * (l_im) + (h03) * (r_im) + (h11) * (l_re) + (h13) * (r_re));
    }
}

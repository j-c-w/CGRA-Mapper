// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/aacpsdsp_float.c

#include <stdint.h>
#include <stdio.h>




typedef float UINTFLOAT;
typedef float INTFLOAT;

int
fn (UINTFLOAT hs0, UINTFLOAT hs3, UINTFLOAT hs1, INTFLOAT h3, INTFLOAT h2,
    INTFLOAT (*r)[2], INTFLOAT (*l)[2], UINTFLOAT hs2, int n, int len,
    INTFLOAT h1, INTFLOAT h0)
{
  for (n = 0; n < len; n++)
    {
      INTFLOAT l_re = l[n][0];
      INTFLOAT l_im = l[n][1];
      INTFLOAT r_re = r[n][0];
      INTFLOAT r_im = r[n][1];
      h0 += hs0;
      h1 += hs1;
      h2 += hs2;
      h3 += hs3;
      l[n][0] = ((h0) * (l_re) + (h2) * (r_re));
      l[n][1] = ((h0) * (l_im) + (h2) * (r_im));
      r[n][0] = ((h1) * (l_re) + (h3) * (r_re));
      r[n][1] = ((h1) * (l_im) + (h3) * (r_im));
    }
}

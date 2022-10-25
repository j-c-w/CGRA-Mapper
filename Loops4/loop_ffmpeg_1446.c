// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/aacpsdsp_fixed.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned UINTFLOAT;
typedef int INTFLOAT;

int
fn (UINTFLOAT hs0, UINTFLOAT hs3, UINTFLOAT hs1, INTFLOAT h3, INTFLOAT h2,
    INTFLOAT (*r)[2], UINTFLOAT hs2, INTFLOAT (*l)[2], int n, int len,
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
      l[n][0] =
	(int) ((((int64_t) (h0) * (l_re)) + ((int64_t) (h2) * (r_re)) +
		0x20000000) >> 30);
      l[n][1] =
	(int) ((((int64_t) (h0) * (l_im)) + ((int64_t) (h2) * (r_im)) +
		0x20000000) >> 30);
      r[n][0] =
	(int) ((((int64_t) (h1) * (l_re)) + ((int64_t) (h3) * (r_re)) +
		0x20000000) >> 30);
      r[n][1] =
	(int) ((((int64_t) (h1) * (l_im)) + ((int64_t) (h3) * (r_im)) +
		0x20000000) >> 30);
}}

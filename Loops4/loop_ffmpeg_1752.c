// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/g723_1enc.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * flt_coef, const int16_t percept_flt_tbl[2][10], int k,
    int16_t * unq_lpc)
{
  int l = 0;
  for (k = 0; k < 10; k++)
    {
      flt_coef[k + 2 * l] =
	(unq_lpc[k + l] * percept_flt_tbl[0][k] + (1 << 14)) >> 15;
      flt_coef[k + 2 * l + 10] =
	(unq_lpc[k + l] * percept_flt_tbl[1][k] + (1 << 14)) >> 15;
    }
}

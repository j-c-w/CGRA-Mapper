// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/aacpsdsp_float.c

#include <stdint.h>
#include <stdio.h>




typedef float INT64FLOAT;
typedef float INTFLOAT;

int
fn (INTFLOAT (*in)[2], int i, const INTFLOAT (*filter)[8][2],
    INT64FLOAT sum_re, INT64FLOAT sum_im, int j)
{
  for (j = 0; j < 6; j++)
    {
      INT64FLOAT in0_re = in[j][0];
      INT64FLOAT in0_im = in[j][1];
      INT64FLOAT in1_re = in[12 - j][0];
      INT64FLOAT in1_im = in[12 - j][1];
      sum_re +=
	(INT64FLOAT) filter[i][j][0] * (in0_re + in1_re) -
	(INT64FLOAT) filter[i][j][1] * (in0_im - in1_im);
      sum_im +=
	(INT64FLOAT) filter[i][j][0] * (in0_im + in1_im) +
	(INT64FLOAT) filter[i][j][1] * (in0_re - in1_re);
    }
}

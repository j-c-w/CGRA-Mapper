// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/aacps_fixed.c

#include <stdint.h>
#include <stdio.h>




typedef int INTFLOAT;
typedef int64_t INT64FLOAT;

int
fn (INT64FLOAT re_op, const INTFLOAT * filter, INTFLOAT (*in)[2],
    INT64FLOAT im_op, int j)
{
  for (j = 0; j < 6; j += 2)
    {
      re_op +=
	(INT64FLOAT) filter[j + 1] * (in[j + 1][0] + in[12 - j - 1][0]);
      im_op +=
	(INT64FLOAT) filter[j + 1] * (in[j + 1][1] + in[12 - j - 1][1]);
    }
}

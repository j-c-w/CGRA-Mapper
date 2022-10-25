// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/aacps_float.c

#include <stdint.h>
#include <stdio.h>




typedef float INT64FLOAT;
typedef float INTFLOAT;

int
fn (int j, const INTFLOAT * filter, INTFLOAT (*in)[2])
{
  INT64FLOAT im_op = 0.0f;
  INT64FLOAT re_op = 0.0f;
  for (j = 0; j < 6; j += 2)
    {
      re_op +=
	(INT64FLOAT) filter[j + 1] * (in[j + 1][0] + in[12 - j - 1][0]);
      im_op +=
	(INT64FLOAT) filter[j + 1] * (in[j + 1][1] + in[12 - j - 1][1]);
    }
}

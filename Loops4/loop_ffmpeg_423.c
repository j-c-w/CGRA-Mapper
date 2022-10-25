// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/faandct.c

#include <stdint.h>
#include <stdio.h>




typedef float FLOAT;
typedef __int16_t int16_t;

int
fn (FLOAT tmp0, FLOAT tmp12, FLOAT tmp3, FLOAT tmp10, FLOAT tmp5, FLOAT tmp13,
    FLOAT z11, FLOAT tmp11, FLOAT z13, FLOAT tmp4, int16_t * data, FLOAT z2,
    FLOAT * temp, FLOAT tmp7, int i, FLOAT z4, FLOAT tmp2, FLOAT tmp1,
    FLOAT tmp6)
{
  for (i = 0; i < 8 * 8; i += 8)
    {
      tmp0 = data[0 + i] + data[7 + i];
      tmp7 = data[0 + i] - data[7 + i];
      tmp1 = data[1 + i] + data[6 + i];
      tmp6 = data[1 + i] - data[6 + i];
      tmp2 = data[2 + i] + data[5 + i];
      tmp5 = data[2 + i] - data[5 + i];
      tmp3 = data[3 + i] + data[4 + i];
      tmp4 = data[3 + i] - data[4 + i];
      tmp10 = tmp0 + tmp3;
      tmp13 = tmp0 - tmp3;
      tmp11 = tmp1 + tmp2;
      tmp12 = tmp1 - tmp2;
      temp[0 + i] = tmp10 + tmp11;
      temp[4 + i] = tmp10 - tmp11;
      tmp12 += tmp13;
      tmp12 *= 0.70710678118654752440;
      temp[2 + i] = tmp13 + tmp12;
      temp[6 + i] = tmp13 - tmp12;
      tmp4 += tmp5;
      tmp5 += tmp6;
      tmp6 += tmp7;
      z2 =
	tmp4 * (0.54119610014619698435 + 0.38268343236508977170) -
	tmp6 * 0.38268343236508977170;
      z4 =
	tmp6 * (1.30656296487637652774 - 0.38268343236508977170) +
	tmp4 * 0.38268343236508977170;
      tmp5 *= 0.70710678118654752440;
      z11 = tmp7 + tmp5;
      z13 = tmp7 - tmp5;
      temp[5 + i] = z13 + z2;
      temp[3 + i] = z13 - z2;
      temp[1 + i] = z11 + z4;
      temp[7 + i] = z11 - z4;
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/cavsdsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int16_t * tmp, ptrdiff_t srcStride, const uint8_t * src1, int i)
{
  const int h = 8;
  for (i = 0; i < h + 5; i++)
    {
      tmp[0] =
	0 * src1[-2] + -7 * src1[-1] + 42 * src1[0] + 96 * src1[1] +
	-2 * src1[2] + -1 * src1[3];
      tmp[1] =
	0 * src1[-1] + -7 * src1[0] + 42 * src1[1] + 96 * src1[2] +
	-2 * src1[3] + -1 * src1[4];
      tmp[2] =
	0 * src1[0] + -7 * src1[1] + 42 * src1[2] + 96 * src1[3] +
	-2 * src1[4] + -1 * src1[5];
      tmp[3] =
	0 * src1[1] + -7 * src1[2] + 42 * src1[3] + 96 * src1[4] +
	-2 * src1[5] + -1 * src1[6];
      tmp[4] =
	0 * src1[2] + -7 * src1[3] + 42 * src1[4] + 96 * src1[5] +
	-2 * src1[6] + -1 * src1[7];
      tmp[5] =
	0 * src1[3] + -7 * src1[4] + 42 * src1[5] + 96 * src1[6] +
	-2 * src1[7] + -1 * src1[8];
      tmp[6] =
	0 * src1[4] + -7 * src1[5] + 42 * src1[6] + 96 * src1[7] +
	-2 * src1[8] + -1 * src1[9];
      tmp[7] =
	0 * src1[5] + -7 * src1[6] + 42 * src1[7] + 96 * src1[8] +
	-2 * src1[9] + -1 * src1[10];
      tmp += 8;
      src1 += srcStride;
    }
}

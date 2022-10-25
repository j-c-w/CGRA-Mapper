// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/cavsdsp.c

#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (ptrdiff_t srcStride, const uint8_t * src1, int16_t * tmp, int i)
{
  const int h = 8;
  for (i = 0; i < h + 5; i++)
    {
      tmp[0] =
	0 * src1[-2] + -1 * src1[-1] + 5 * src1[0] + 5 * src1[1] +
	-1 * src1[2] + 0 * src1[3];
      tmp[1] =
	0 * src1[-1] + -1 * src1[0] + 5 * src1[1] + 5 * src1[2] +
	-1 * src1[3] + 0 * src1[4];
      tmp[2] =
	0 * src1[0] + -1 * src1[1] + 5 * src1[2] + 5 * src1[3] +
	-1 * src1[4] + 0 * src1[5];
      tmp[3] =
	0 * src1[1] + -1 * src1[2] + 5 * src1[3] + 5 * src1[4] +
	-1 * src1[5] + 0 * src1[6];
      tmp[4] =
	0 * src1[2] + -1 * src1[3] + 5 * src1[4] + 5 * src1[5] +
	-1 * src1[6] + 0 * src1[7];
      tmp[5] =
	0 * src1[3] + -1 * src1[4] + 5 * src1[5] + 5 * src1[6] +
	-1 * src1[7] + 0 * src1[8];
      tmp[6] =
	0 * src1[4] + -1 * src1[5] + 5 * src1[6] + 5 * src1[7] +
	-1 * src1[8] + 0 * src1[9];
      tmp[7] =
	0 * src1[5] + -1 * src1[6] + 5 * src1[7] + 5 * src1[8] +
	-1 * src1[9] + 0 * src1[10];
      tmp += 8;
      src1 += srcStride;
    }
}

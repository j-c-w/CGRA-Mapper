// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/h264qpel.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint16_t uint16_t;

int
fn (int32_t * tmp, int i, int srcStride, const int pad, int tmpStride,
    const uint16_t * src)
{
  const int h = 8;
  for (i = 0; i < h + 5; i++)
    {
      tmp[0] =
	(src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 + (src[-2] + src[3]) +
	pad;
      tmp[1] =
	(src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 + (src[-1] + src[4]) +
	pad;
      tmp[2] =
	(src[2] + src[3]) * 20 - (src[1] + src[4]) * 5 + (src[0] + src[5]) +
	pad;
      tmp[3] =
	(src[3] + src[4]) * 20 - (src[2] + src[5]) * 5 + (src[1] + src[6]) +
	pad;
      tmp[4] =
	(src[4] + src[5]) * 20 - (src[3] + src[6]) * 5 + (src[2] + src[7]) +
	pad;
      tmp[5] =
	(src[5] + src[6]) * 20 - (src[4] + src[7]) * 5 + (src[3] + src[8]) +
	pad;
      tmp[6] =
	(src[6] + src[7]) * 20 - (src[5] + src[8]) * 5 + (src[4] + src[9]) +
	pad;
      tmp[7] =
	(src[7] + src[8]) * 20 - (src[6] + src[9]) * 5 + (src[5] + src[10]) +
	pad;
      tmp += tmpStride;
      src += srcStride;
    }
}

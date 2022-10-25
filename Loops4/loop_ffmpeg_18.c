// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/rv30dsp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int dstStride, const uint8_t * src, int srcStride, const int C1,
    const int C2, const uint8_t * cm, uint8_t * dst)
{
  const int h = 8;
  for (i = 0; i < h; i++)
    {
      dst[0] = cm[(-(src[-1] + src[2]) + src[0] * C1 + src[1] * C2 + 8) >> 4];
      dst[1] = cm[(-(src[0] + src[3]) + src[1] * C1 + src[2] * C2 + 8) >> 4];
      dst[2] = cm[(-(src[1] + src[4]) + src[2] * C1 + src[3] * C2 + 8) >> 4];
      dst[3] = cm[(-(src[2] + src[5]) + src[3] * C1 + src[4] * C2 + 8) >> 4];
      dst[4] = cm[(-(src[3] + src[6]) + src[4] * C1 + src[5] * C2 + 8) >> 4];
      dst[5] = cm[(-(src[4] + src[7]) + src[5] * C1 + src[6] * C2 + 8) >> 4];
      dst[6] = cm[(-(src[5] + src[8]) + src[6] * C1 + src[7] * C2 + 8) >> 4];
      dst[7] = cm[(-(src[6] + src[9]) + src[7] * C1 + src[8] * C2 + 8) >> 4];
      dst += dstStride;
      src += srcStride;
    }
}

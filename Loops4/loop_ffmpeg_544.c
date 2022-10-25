// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/h264chroma.c

#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (int i, ptrdiff_t stride, int h, uint16_t * src, const int A,
    const ptrdiff_t step, uint16_t * dst, const int E)
{
  for (i = 0; i < h; i++)
    {
      dst[0] = ((((A * src[0] + E * src[step + 0])) + 32) >> 6);
      dst[1] = ((((A * src[1] + E * src[step + 1])) + 32) >> 6);
      dst[2] = ((((A * src[2] + E * src[step + 2])) + 32) >> 6);
      dst[3] = ((((A * src[3] + E * src[step + 3])) + 32) >> 6);
      dst[4] = ((((A * src[4] + E * src[step + 4])) + 32) >> 6);
      dst[5] = ((((A * src[5] + E * src[step + 5])) + 32) >> 6);
      dst[6] = ((((A * src[6] + E * src[step + 6])) + 32) >> 6);
      dst[7] = ((((A * src[7] + E * src[step + 7])) + 32) >> 6);
      dst += stride;
      src += stride;
    }
}

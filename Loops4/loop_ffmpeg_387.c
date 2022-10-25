// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/h264dsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint16_t uint16_t;

int
fn (int stride, uint16_t * dst, int i, int32_t * src)
{
  for (i = 0; i < 4; i++)
    {
      dst[0] += (unsigned) src[0];
      dst[1] += (unsigned) src[1];
      dst[2] += (unsigned) src[2];
      dst[3] += (unsigned) src[3];
      dst += stride;
      src += 4;
}}

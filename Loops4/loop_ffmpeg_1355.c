// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/sbrdsp.c

#include <stdint.h>
#include <stdio.h>




typedef union av_intfloat32
{
  uint32_t i;
  float f;
} av_intfloat32;

int
fn (const union av_intfloat32 *zi, union av_intfloat32 *Wi, int k)
{
  for (k = 0; k < 32; k += 2)
    {
      Wi[2 * k + 0].i = zi[63 - k].i ^ (1U << 31);
      Wi[2 * k + 1].i = zi[k + 0].i;
      Wi[2 * k + 2].i = zi[62 - k].i ^ (1U << 31);
      Wi[2 * k + 3].i = zi[k + 1].i;
    }
}

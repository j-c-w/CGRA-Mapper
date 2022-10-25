// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/sbrdsp.c

#include <stdint.h>
#include <stdio.h>




typedef union av_intfloat32
{
  uint32_t i;
  float f;
} av_intfloat32;

int
fn (union av_intfloat32 *zi, int k)
{
  for (k = 1; k < 31; k += 2)
    {
      zi[64 + 2 * k + 0].i = zi[64 - k].i ^ (1U << 31);
      zi[64 + 2 * k + 1].i = zi[k + 1].i;
      zi[64 + 2 * k + 2].i = zi[63 - k].i ^ (1U << 31);
      zi[64 + 2 * k + 3].i = zi[k + 2].i;
    }
}

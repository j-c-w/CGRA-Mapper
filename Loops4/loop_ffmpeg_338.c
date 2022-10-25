// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/sbrdsp.c

#include <stdint.h>
#include <stdio.h>




typedef union av_intfloat32
{
  uint32_t i;
  float f;
} av_intfloat32;

int
fn (const union av_intfloat32 *si, union av_intfloat32 *vi, int i)
{
  for (i = 0; i < 32; i++)
    {
      vi[i].i = si[63 - 2 * i].i;
      vi[63 - i].i = si[63 - 2 * i - 1].i ^ (1U << 31);
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/sbrdsp.c

#include <stdint.h>
#include <stdio.h>




typedef union av_intfloat32
{
  uint32_t i;
  float f;
} av_intfloat32;

int
fn (int i, union av_intfloat32 *xi)
{
  for (i = 1; i < 64; i += 4)
    {
      xi[i + 0].i ^= 1U << 31;
      xi[i + 2].i ^= 1U << 31;
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/sbrdsp.c

#include <stdint.h>
#include <stdio.h>




typedef float INTFLOAT;

int
fn (INTFLOAT * v, const INTFLOAT * src0, int i, const INTFLOAT * src1)
{
  for (i = 0; i < 64; i++)
    {
      v[i] = src0[i] - src1[63 - i];
      v[127 - i] = src0[i] + src1[63 - i];
    }
}

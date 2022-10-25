// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/jpeg2000dwt.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int i1, int32_t * p, int i0, int i)
{
  for (i = 1; i <= 4; i++)
    {
      p[i0 - i] = p[i0 + i];
      p[i1 + i - 1] = p[i1 - i - 1];
    }
}

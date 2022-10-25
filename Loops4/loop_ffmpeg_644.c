// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/aacdec_fixed.c

#include <stdint.h>
#include <stdio.h>




typedef int INTFLOAT;

int
fn (const int n, int i, INTFLOAT * buf)
{
  for (i = 0; i < n; i += 2)
    {
      buf[i] = -buf[i];
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/sbrdsp_fixed.c

#include <stdint.h>
#include <stdio.h>






int
fn (const int *src, int i, int *v)
{
  for (i = 0; i < 32; i++)
    {
      v[i] = (src[63 - 2 * i] + 0x10) >> 5;
      v[63 - i] = (-src[63 - 2 * i - 1] + 0x10) >> 5;
    }
}

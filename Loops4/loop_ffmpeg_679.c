// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/takdec.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * p2, int order_half, int32_t * p1, int i)
{
  for (i = 0; i < order_half; i++)
    {
      int32_t a = p1[i];
      int32_t b = p2[i];
      p1[i] = a + b;
    }
}

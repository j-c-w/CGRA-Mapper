// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/flacenc.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * right, int i, int32_t * left, int n, int32_t tmp)
{
  for (i = 0; i < n; i++)
    {
      tmp = left[i];
      left[i] = (tmp + right[i]) >> 1;
      right[i] = tmp - right[i];
    }
}

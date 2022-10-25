// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_showinfo.c

#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __uint8_t uint8_t;

int
fn (int i, int64_t * sum, const uint8_t * src, int len, int64_t * sum2)
{
  for (i = 0; i < len; i++)
    {
      *sum += src[i];
      *sum2 += src[i] * src[i];
    }
}

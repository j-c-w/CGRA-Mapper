// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/flacenc.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint64_t uint64_t;

int
fn (int i, int n, uint64_t count, const int32_t * res, int k)
{
  for (i = 0; i < n; i++)
    {
      int32_t v = -2 * res[i] - 1;
      v ^= v >> 31;
      count += (v >> k) + 1 + k;
    }
}

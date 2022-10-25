// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/xsubenc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;

int
fn (uint64_t ms, const int tc_divs[3], int i, int *tc)
{
  for (i = 0; i < 3; i++)
    {
      tc[i] = ms % tc_divs[i];
      ms /= tc_divs[i];
    }
}

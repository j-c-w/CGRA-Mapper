// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/exr.c

#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;

int
fn (uint64_t c, int i, uint64_t n[59])
{
  for (i = 58; i > 0; --i)
    {
      uint64_t nc = ((c + n[i]) >> 1);
      n[i] = c;
      c = nc;
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_midequalizer.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int w0, int x, unsigned int *cchange, const uint16_t * i, uint16_t * d)
{
  for (x = 0; x < w0; x++)
    {
      d[x] = cchange[i[x]];
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/x86/snowdsp.c

#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (IDWTELEM * high, int *i, IDWTELEM * low)
{
  for (; (*i) >= 0; (*i) -= 2)
    {
      low[(*i) + 1] = high[(*i) >> 1];
      low[*i] = low[(*i) >> 1];
    }
}

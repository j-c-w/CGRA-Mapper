// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/pixlet.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int16_t * hh, int16_t * lh, int16_t * hl, int16_t * low, int j,
    int16_t * high, int16_t * ll)
{
  for (i = 4, j = 2; i; i--, j++, ll--, hh++, lh++, hl--)
    {
      low[i - 5] = low[j - 1];
      lh[0] = ll[-1];
      high[i - 5] = high[j - 2];
      hh[0] = hl[-2];
    }
}

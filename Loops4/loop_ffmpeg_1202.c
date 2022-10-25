// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/g723_1dec.c

#include <stdint.h>
#include <stdio.h>






int
fn (int j, int i, int signs[22], int t)
{
  for (j = 0; j < 11; j++)
    {
      signs[i * 11 + j] = ((t & 1) * 2 - 1) * (1 << 14);
      t >>= 1;
    }
}

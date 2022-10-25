// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mpegaudioenc_float.c

#include <stdint.h>
#include <stdio.h>






int
fn (int *tab, int *out, int i, const int bitinv32[32])
{
  for (i = 0; i < 32; i++)
    {
      out[i] = tab[bitinv32[i]];
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ilbcdec.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, int32_t f[2][6])
{
  for (i = 5; i > 0; i--)
    {
      f[0][i] += (unsigned) f[0][i - 1];
      f[1][i] -= (unsigned) f[1][i - 1];
}}

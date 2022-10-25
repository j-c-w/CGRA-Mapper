// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/hevcdsp.c

#include <stdint.h>
#include <stdio.h>






int
fn (int o_8[4], int e_16[8], int i, int e_8[4])
{
  for (i = 0; i < 4; i++)
    {
      (e_16[i * 1]) = (e_8[i] + o_8[i]);
      (e_16[(7 - i) * 1]) = (e_8[i] - o_8[i]);
    }
}

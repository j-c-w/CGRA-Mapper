// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/vp8dsp.c

#include <stdint.h>
#include <stdio.h>






int
fn (int16_t (*block)[4][16], int i, int val)
{
  for (i = 0; i < 4; i++)
    {
      block[i][0][0] = val;
      block[i][1][0] = val;
      block[i][2][0] = val;
      block[i][3][0] = val;
    }
}

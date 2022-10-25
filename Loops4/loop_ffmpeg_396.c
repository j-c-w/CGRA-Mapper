// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/vp8dsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int t3, int16_t * dc, int t0, int t1, int t2)
{
  for (i = 0; i < 4; i++)
    {
      t0 = dc[0 * 4 + i] + dc[3 * 4 + i];
      t1 = dc[1 * 4 + i] + dc[2 * 4 + i];
      t2 = dc[1 * 4 + i] - dc[2 * 4 + i];
      t3 = dc[0 * 4 + i] - dc[3 * 4 + i];
      dc[0 * 4 + i] = t0 + t1;
      dc[1 * 4 + i] = t3 + t2;
      dc[2 * 4 + i] = t0 - t1;
      dc[3 * 4 + i] = t3 - t2;
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/vp8dsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int t1, int i, int16_t * block, int16_t tmp[16], int t0, int t3, int t2)
{
  for (i = 0; i < 4; i++)
    {
      t0 = block[0 * 4 + i] + block[2 * 4 + i];
      t1 = block[0 * 4 + i] - block[2 * 4 + i];
      t2 =
	(((block[1 * 4 + i]) * 35468) >> 16) -
	((((block[3 * 4 + i]) * 20091) >> 16) + (block[3 * 4 + i]));
      t3 =
	((((block[1 * 4 + i]) * 20091) >> 16) + (block[1 * 4 + i])) +
	(((block[3 * 4 + i]) * 35468) >> 16);
      block[0 * 4 + i] = 0;
      block[1 * 4 + i] = 0;
      block[2 * 4 + i] = 0;
      block[3 * 4 + i] = 0;
      tmp[i * 4 + 0] = t0 + t3;
      tmp[i * 4 + 1] = t1 + t2;
      tmp[i * 4 + 2] = t1 - t2;
      tmp[i * 4 + 3] = t0 - t3;
    }
}

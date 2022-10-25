// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/g723_1.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int f2[6], int f1[6], int16_t * lpc, int j)
{
  for (j = i; j >= 2; j--)
    {
      f1[j] =
	((((f1[j - 1]) >> 16) * (lpc[2 * i]) * 2) +
	 (((f1[j - 1]) & 0xffff) * (lpc[2 * i]) >> 15)) + (f1[j] >> 1) +
	(f1[j - 2] >> 1);
      f2[j] =
	((((f2[j - 1]) >> 16) * (lpc[2 * i + 1]) * 2) +
	 (((f2[j - 1]) & 0xffff) * (lpc[2 * i + 1]) >> 15)) + (f2[j] >> 1) +
	(f2[j - 2] >> 1);
    }
}

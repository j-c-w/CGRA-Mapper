// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/vc1dsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int t1, int i, int t6, int16_t * dst, int t8, int t5, int16_t * src,
    int t7, int t3, int t4, int t2)
{
  for (i = 0; i < 8; i++)
    {
      t1 = 12 * (src[0] + src[32]) + 4;
      t2 = 12 * (src[0] - src[32]) + 4;
      t3 = 16 * src[16] + 6 * src[48];
      t4 = 6 * src[16] - 16 * src[48];
      t5 = t1 + t3;
      t6 = t2 + t4;
      t7 = t2 - t4;
      t8 = t1 - t3;
      t1 = 16 * src[8] + 15 * src[24] + 9 * src[40] + 4 * src[56];
      t2 = 15 * src[8] - 4 * src[24] - 16 * src[40] - 9 * src[56];
      t3 = 9 * src[8] - 16 * src[24] + 4 * src[40] + 15 * src[56];
      t4 = 4 * src[8] - 9 * src[24] + 15 * src[40] - 16 * src[56];
      dst[0] = (t5 + t1) >> 3;
      dst[1] = (t6 + t2) >> 3;
      dst[2] = (t7 + t3) >> 3;
      dst[3] = (t8 + t4) >> 3;
      dst[4] = (t8 - t4) >> 3;
      dst[5] = (t7 - t3) >> 3;
      dst[6] = (t6 - t2) >> 3;
      dst[7] = (t5 - t1) >> 3;
      src += 1;
      dst += 8;
    }
}

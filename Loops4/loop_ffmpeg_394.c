// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/tscc2.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, int *in, int t3, int *q, int tblk[16], int t0, int t1, int t2)
{
  for (i = 0; i < 4; i++)
    {
      t0 = (((in[0 * 4 + i]) * (q[0 + (i & 1)]) + 0x80) >> 8);
      t1 = (((in[1 * 4 + i]) * (q[1 + (i & 1)]) + 0x80) >> 8);
      t2 = (((in[2 * 4 + i]) * (q[0 + (i & 1)]) + 0x80) >> 8);
      t3 = (((in[3 * 4 + i]) * (q[1 + (i & 1)]) + 0x80) >> 8);
      tblk[0 * 4 + i] = (5 * ((t0) + (t1) + (t2)) + 2 * (t3));
      tblk[1 * 4 + i] = (5 * ((t0) - (t2) - (t3)) + 2 * (t1));
      tblk[2 * 4 + i] = (5 * ((t0) - (t2) + (t3)) - 2 * (t1));
      tblk[3 * 4 + i] = (5 * ((t0) - (t1) + (t2)) - 2 * (t3));;
    }
}

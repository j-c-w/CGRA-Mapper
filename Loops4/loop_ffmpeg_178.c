// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/sbcdsp.c

#include <stdint.h>
#include <stdio.h>






int
fn (int32_t sb_sample_j[16][2], int32_t (*sb_sample_f)[2][8], int blk, int sb,
    int blocks)
{
  for (blk = 0; blk < blocks; blk++)
    {
      sb_sample_f[blk][0][sb] = sb_sample_j[blk][0];
      sb_sample_f[blk][1][sb] = sb_sample_j[blk][1];
    }
}

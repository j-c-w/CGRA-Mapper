// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/atrac3.c

#include <stdint.h>
#include <stdio.h>






int
fn (float *su2, float w[2][2], int band, float *su1, int nsample)
{
  for (; nsample < band + 256; nsample++)
    {
      su1[nsample] *= w[1][0];
      su2[nsample] *= w[1][1];
    }
}

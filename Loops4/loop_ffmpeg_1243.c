// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_bm3d.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *bufferv, float *bufferh, int j, const int block_size)
{
  for (j = 0; j < block_size; j++)
    {
      bufferv[i * block_size + j] = bufferh[j * block_size + i];
    }
}

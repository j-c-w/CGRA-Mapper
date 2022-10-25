// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_bm3d.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *num, float num_weight, float *den, float *bufferh, int j,
    const int block_size, float den_weight)
{
  for (j = 0; j < block_size; j++)
    {
      num[j] += bufferh[i * block_size + j] * num_weight;
      den[j] += den_weight;
    }
}

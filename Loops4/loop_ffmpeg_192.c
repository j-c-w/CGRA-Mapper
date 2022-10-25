// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/wmaprodec.c

#include <stdint.h>
#include <stdio.h>






int
fn (float *data_ptr, int y, float **ch_data, float data[8], float **ch_end,
    const float *mat, float **ch, const float *data_end)
{
  for (ch = ch_data; ch < ch_end; ch++)
    {
      float sum = 0;
      data_ptr = data;
      while (data_ptr < data_end)
	sum += *data_ptr++ * *mat++;
      (*ch)[y] = sum;
    }
}

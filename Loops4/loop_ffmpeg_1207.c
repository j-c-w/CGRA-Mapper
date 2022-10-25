// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/cook.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *decode_buffer, int j, float *mlt_buffer_right,
    float *mlt_buffer_left)
{
  for (j = 0; j < 20; j++)
    {
      mlt_buffer_left[i * 20 + j] = decode_buffer[i * 40 + j];
      mlt_buffer_right[i * 20 + j] = decode_buffer[i * 40 + 20 + j];
    }
}

// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/twinvq.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *out, float v2, int size, float step)
{
  for (i = 0; i < size; i++)
    {
      v2 += step;
      out[i] = v2;
    }
}

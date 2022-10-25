// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/asrc_sinc.c

#include <stdint.h>
#include <stdio.h>






int
fn (float *work, int work_len, int i)
{
  for (i = 1; i < work_len / 2; i++)
    {
      work[i] *= 2;
      work[i + work_len / 2] = 0;
    }
}

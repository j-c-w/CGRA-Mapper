// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/asrc_sinc.c

#include <stdint.h>
#include <stdio.h>






int
fn (int work_len, int i, float *work, float phase, int begin, int *len,
    float **h)
{
  for (i = 0; i < *len; i++)
    {
      (*h)[i] =
	work[(begin + (phase > 50.f ? *len - 1 - i : i) +
	      work_len) & (work_len - 1)];
    }
}

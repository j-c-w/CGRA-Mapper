// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_hdcd.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * samples, int i, const int32_t gaintab[1921], int len, int gain,
    int stride)
{
  for (i = 0; i < len; i++)
    {
      ++gain;
      do
	{
	  int64_t s64 = *samples;
	  s64 *= gaintab[gain];
	  *samples = (int32_t) (s64 >> 23);
	}
      while (0);;
      samples += stride;
    }
}
